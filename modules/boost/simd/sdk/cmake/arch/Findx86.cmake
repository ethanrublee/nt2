################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

include(CheckCXXCompilerFlag)

################################################################################
# Force scalar computation to use SIMD unit
################################################################################
macro(nt2_simd_set_fpmath ext)
  string(TOLOWER ${ext} ext_l)
  set(ext_u ${ext})

  if(NT2_COMPILER_GNU_C)
      
      if(NOT ext_l STREQUAL avx)
        set(ext_l sse)
        set(ext_u SSE)
      endif()

      check_cxx_compiler_flag("-mfpmath=${ext_l}" HAS_GCC_MFPMATH_${ext_u})
      if(HAS_GCC_MFPMATH_${ext_u})
        set(NT2_SIMD_FLAGS "${NT2_SIMD_FLAGS} -mfpmath=${ext_l}")
      endif()

  elseif(NT2_COMPILER_MSVC)
  
    if(NOT ext STREQUAL AVX AND NOT ext STREQUAL SSE)
      set(ext_u SSE2)
    endif()
    
    check_cxx_compiler_flag("/arch:${ext_u}" HAS_MSVC_ARCH_${ext_u})
    if(HAS_MSVC_ARCH_${ext_u})
      set(NT2_SIMD_FLAGS "${NT2_SIMD_FLAGS} /arch:${ext_u}")
    endif()
  endif()
  
endmacro()

################################################################################
# Detect best SIMD capability on host machine
################################################################################
macro(nt2_simd_cpuid_check ext)

  # Check for ext availability
  string(TOLOWER ${ext} ext_l)
  string(REPLACE "_" "." ext_l ${ext_l})
    
  find_file(SRC_CPUID src/cpuid.cpp ${CMAKE_MODULE_PATH} NO_DEFAULT_PATH)
  set(SRC_CPUID ${SRC_CPUID} CACHE INTERNAL "" FORCE)
  try_run(RUN_RESULT_VAR COMPILE_RESULT_VAR
          ${PROJECT_BINARY_DIR}/cmake
          ${SRC_CPUID}
          OUTPUT_VARIABLE LOG
          ARGS ${ext_l}
         )

  # If file compiles and doesn't return an error, host CPU supports the extension
  if(COMPILE_RESULT_VAR AND RUN_RESULT_VAR EQUAL 0)
    set(NT2_HAS_${ext}_SUPPORT 1)
  else()
    set(NT2_HAS_${ext}_SUPPORT 0)
  endif()

  if(NT2_HAS_${ext}_SUPPORT)
    check_cxx_compiler_flag("-m${ext_l}" HAS_GCC_${ext})
    if(HAS_GCC_${ext})
      set(NT2_SIMD_FLAGS "-m${ext_l}")
    else()
      # find a way to test if compiler really supports it?
      set(NT2_SIMD_FLAGS "-DBOOST_SIMD_HAS_${ext}_SUPPORT")
    endif()
  endif()
      
  if(NT2_HAS_${ext}_SUPPORT)
    message(STATUS "[boost.simd.sdk] ${ext} available")
    nt2_simd_set_fpmath(${ext})
    set(NT2_SIMD_FLAGS ${NT2_SIMD_FLAGS} PARENT_SCOPE)
    return()
  else()
    message(STATUS "[boost.simd.sdk] ${ext} not available")
  endif()
  
endmacro()

function(nt2_simd_cpuid_find)
  if(NT2_ARCH_AMD)
    nt2_simd_cpuid_check(XOP)
    nt2_simd_cpuid_check(FMA4)
  endif()
  nt2_simd_cpuid_check(AVX)
  nt2_simd_cpuid_check(SSE4_2)
  nt2_simd_cpuid_check(SSE4_1)
  nt2_simd_cpuid_check(SSSE3)
  if(NT2_ARCH_AMD)
    nt2_simd_cpuid_check(SSE4A)
  endif()
  nt2_simd_cpuid_check(SSE3)
  nt2_simd_cpuid_check(SSE2)
  nt2_simd_cpuid_check(SSE)
  
  set(NT2_SIMD_FLAGS " " PARENT_SCOPE)
  
endfunction()

nt2_simd_cpuid_find()
