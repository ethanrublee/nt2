################################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0.
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
################################################################################

macro(nt2_module_install_setup)
  if(NOT UNIX)
    set( NT2_INSTALL_SHARE_DIR .
         CACHE PATH "Directory where to install extra files"
       )
  else()
    set( NT2_INSTALL_SHARE_DIR share/nt2
         CACHE PATH "Directory where to install extra files"
       )
  endif()

endmacro()

macro(nt2_module_source_setup module)
  string(TOUPPER ${module} NT2_CURRENT_MODULE_U)
  
  set(NT2_CURRENT_MODULE ${module})
  set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)
  
  include_directories(${NT2_${NT2_CURRENT_MODULE_U}_INCLUDE_DIR})
  link_directories(${NT2_${NT2_CURRENT_MODULE_U}_DEPENDENCIES_LIBRARY_DIR})
  link_libraries(${NT2_${NT2_CURRENT_MODULE_U}_DEPENDENCIES_LIBRARIES})
  set(NT2_CURRENT_FLAGS "${NT2_CURRENT_FLAGS} ${NT2_${NT2_CURRENT_MODULE_U}_FLAGS}")
  
  file(WRITE ${PROJECT_BINARY_DIR}/modules/${module}.manifest)
  
  # installation is only done when current project is NT2
  # or same as current module
  if(PROJECT_NAME STREQUAL NT2 OR PROJECT_NAME STREQUAL "NT2_${NT2_CURRENT_MODULE_U}")

    nt2_module_install_setup()

    # set up component
    cpack_add_component(${module}
                        DEPENDS ${NT2_${NT2_CURRENT_MODULE_U}_DEPENDENCIES_EXTRA}
                       )
  
    # install headers, cmake modules and manifest
    install( DIRECTORY ${NT2_${NT2_CURRENT_MODULE_U}_ROOT}/include/
             DESTINATION include
             COMPONENT ${module}
             FILES_MATCHING PATTERN "*.hpp"
           )
    install( FILES ${PROJECT_BINARY_DIR}/modules/${module}.manifest
             DESTINATION ${NT2_INSTALL_SHARE_DIR}/modules
             COMPONENT ${module}
           )
    install( DIRECTORY ${NT2_${NT2_CURRENT_MODULE_U}_ROOT}/cmake
             DESTINATION ${NT2_INSTALL_SHARE_DIR}
             COMPONENT ${module}
             FILES_MATCHING PATTERN "*.cmake"
                            PATTERN "*.cpp"
           )
  endif()
  
endmacro()

macro(nt2_setup_variant)
  if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
  elseif(CMAKE_BUILD_TYPE STREQUAL Debug)
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -DNT2_DEBUG")
    set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -DNT2_DEBUG")
  endif()
endmacro()

function(nt2_module_target_parent target)
  string(REGEX REPLACE "[^.]+\\.([^.]+)$" "\\1" parent_target ${target})

  if(NOT parent_target STREQUAL ${target})
    get_target_property(${parent_target}_exists ${parent_target} EXCLUDE_FROM_ALL)
    if(${parent_target}_exists MATCHES "NOTFOUND$")
      add_custom_target(${parent_target})
    endif()
    add_dependencies(${parent_target} ${target})
  
    nt2_module_target_parent(${parent_target})
  endif()
  
endfunction()

macro(nt2_module_dir dir)
  if(IS_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/${dir})
      add_custom_target(${NT2_CURRENT_MODULE}.${dir})
      nt2_module_target_parent(${NT2_CURRENT_MODULE}.${dir})
      add_subdirectory(${dir})
    endif()
endmacro()

macro(nt2_module_main module)
  string(TOUPPER ${module} NT2_CURRENT_MODULE_U)
    
  if(CMAKE_CURRENT_SOURCE_DIR STREQUAL ${PROJECT_SOURCE_DIR})
    project(NT2_${NT2_CURRENT_MODULE_U})
    nt2_postconfigure_init()
  endif()

  nt2_setup_variant()
  
  set(NT2_CURRENT_MODULE ${module})
  nt2_module_use_modules(${module})
  
  if(CMAKE_GENERATOR MATCHES "Make")
    set(NT2_WITH_TESTS_ 1)
  else()
    set(NT2_WITH_TESTS_ 0)
  endif()
  option(NT2_WITH_TESTS "Enable benchmarks and unit tests" ${NT2_WITH_TESTS_})
  option(NT2_WITH_TESTS_COVER "Enable cover tests" OFF)
  
  if(NT2_WITH_TESTS_COVER AND NOT NT2_WITH_TESTS)
    set(NT2_WITH_TESTS 1 CACHE BOOL "Enable benchmarks and unit tests" FORCE)
  endif()

  if(NT2_WITH_TESTS)
    ENABLE_TESTING()
    
    nt2_module_dir(bench)
    nt2_module_dir(examples)
    nt2_module_dir(unit)
    
    if(NT2_WITH_TESTS_COVER)
      nt2_module_dir(cover)
    endif()
  endif()
  
  if(PROJECT_NAME STREQUAL "NT2_${NT2_CURRENT_MODULE_U}")
    nt2_postconfigure_run()
  endif()
endmacro()

macro(nt2_module_add_library libname)
  string(TOUPPER ${NT2_CURRENT_MODULE} NT2_CURRENT_MODULE_U)
  
  if(DEFINED NT2_USE_STATIC_LIBS AND NOT DEFINED NT2_${NT2_CURRENT_MODULE_U}_USE_STATIC_LIBS)
    set(NT2_${NT2_CURRENT_MODULE_U}_USE_STATIC_LIBS NT2_USE_STATIC_LIBS)
  endif()

  if(DEFINED NT2_${NT2_CURRENT_MODULE_U}_USE_STATIC_LIBS)
    if(NT2_${NT2_CURRENT_MODULE_U}_USE_STATIC_LIBS)
      add_library(${libname} SHARED ${ARGN})
      set(NT2_${NT2_CURRENT_MODULE_U}_DYN_LINK 1)
    else()
      add_library(${libname} STATIC ${ARGN})
    endif()
  else()
    add_library(${libname} ${ARGN})
    set(NT2_${NT2_CURRENT_MODULE_U}_DYN_LINK ${BUILD_SHARED_LIBS})
  endif()

  set_target_properties(${libname} PROPERTIES VERSION 3.0.0 SOVERSION 3)
  
  if(${NT2_CURRENT_MODULE} MATCHES "^boost\\.")
    string(REPLACE "." "_" macro_name ${NT2_CURRENT_MODULE_U})
  else()
    string(REPLACE "." "__" macro_name "NT2_${NT2_CURRENT_MODULE_U}")
  endif()
  set(FLAGS "${NT2_CURRENT_FLAGS} -D${macro_name}_SOURCE")
  if(NT2_${NT2_CURRENT_MODULE_U}_DYN_LINK)
    set(FLAGS "${FLAGS} -D${macro_name}_DYN_LINK")
  endif()
  set_property(TARGET ${libname} PROPERTY COMPILE_FLAGS ${FLAGS})
  
  if(PROJECT_NAME STREQUAL NT2 OR PROJECT_NAME STREQUAL "NT2_${NT2_CURRENT_MODULE_U}")
    install( TARGETS ${libname}
             LIBRARY DESTINATION lib COMPONENT ${NT2_CURRENT_MODULE} CONFIGURATIONS Release
             ARCHIVE DESTINATION lib COMPONENT ${NT2_CURRENT_MODULE} CONFIGURATIONS Release
             RUNTIME DESTINATION lib COMPONENT ${NT2_CURRENT_MODULE} CONFIGURATIONS Release
           )
  endif()
  
endmacro()

macro(nt2_module_use_modules)

  string(REGEX REPLACE "^.*/(.*)$" "\\1" component "${CMAKE_CURRENT_SOURCE_DIR}")
  if(NOT component STREQUAL ${NT2_CURRENT_MODULE})
    set(component_ " ${component}:")
  endif()

  #message(STATUS "[nt2.${NT2_CURRENT_MODULE}]${component_} checking dependencies...")
  
  find_package(NT2 COMPONENTS ${ARGN})
  if(NOT NT2_FOUND)
    message(STATUS "[nt2.${NT2_CURRENT_MODULE}] warning:${component_} dependencies not met, skipping")
    return()
  endif()

  include_directories(${NT2_INCLUDE_DIR})
  link_directories(${NT2_LIBRARY_DIR})
  link_libraries(${NT2_LIBRARIES})
  
  set(NT2_CURRENT_FLAGS "${NT2_CURRENT_FLAGS} ${NT2_FLAGS}")
endmacro()

macro(nt2_module_add_exe DIRECTORY EXECUTABLE)
  string(TOUPPER ${NT2_CURRENT_MODULE} NT2_CURRENT_MODULE_U)

  add_executable(${EXECUTABLE} EXCLUDE_FROM_ALL ${ARGN})
  
  set_property(TARGET ${EXECUTABLE} PROPERTY COMPILE_FLAGS ${NT2_CURRENT_FLAGS})
  set_property(TARGET ${EXECUTABLE} PROPERTY RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/${DIRECTORY})
endmacro()

macro(nt2_module_add_test DIRECTORY EXECUTABLE)
  nt2_module_add_exe(${DIRECTORY} ${EXECUTABLE} ${ARGN})

  string(REGEX REPLACE "\\.([^.]+)\\.${DIRECTORY}$" ".${DIRECTORY}" suite ${EXECUTABLE})
  string(REGEX REPLACE "\\.${DIRECTORY}$" "-${DIRECTORY}" TEST ${EXECUTABLE})
  
  add_dependencies(${suite} ${EXECUTABLE})
  if(NOT CMAKE_CROSSCOMPILING_HOST AND DEFINED ENV{CMAKE_CROSSCOMPILING_HOST})
    set(CMAKE_CROSSCOMPILING_HOST $ENV{CMAKE_CROSSCOMPILING_HOST})
  endif()
  if(CMAKE_CROSSCOMPILING AND CMAKE_CROSSCOMPILING_HOST)
    add_test(${TEST} /bin/sh -c "scp ${PROJECT_BINARY_DIR}/${DIRECTORY}/${EXECUTABLE} ${CMAKE_CROSSCOMPILING_HOST}:/tmp && ssh ${CMAKE_CROSSCOMPILING_HOST} /tmp/${EXECUTABLE} && ssh ${CMAKE_CROSSCOMPILING_HOST} rm /tmp/${EXECUTABLE}")
  else()
    add_test(${TEST} ${PROJECT_BINARY_DIR}/${DIRECTORY}/${EXECUTABLE})
  endif()
endmacro()

macro(nt2_module_add_unit)
  nt2_module_add_test(unit ${ARGN})
endmacro()

macro(nt2_module_add_cover)
  nt2_module_add_test(cover ${ARGN})
endmacro()

macro(nt2_module_add_bench EXECUTABLE)
  nt2_module_add_exe(bench ${EXECUTABLE} ${ARGN})

  string(REGEX REPLACE "\\.([^.]+)\\.bench$" ".bench" suite ${EXECUTABLE})
  
  add_dependencies(${suite} ${EXECUTABLE})
endmacro()

macro(nt2_module_add_example EXECUTABLE)
  nt2_module_add_exe(examples ${EXECUTABLE} ${ARGN})

  string(REGEX REPLACE "\\.([^.]+)\\.sample$" ".examples" suite ${EXECUTABLE})
  
  add_dependencies(${suite} ${EXECUTABLE})
endmacro()

macro(nt2_module_install_file header)
  string(TOUPPER ${NT2_CURRENT_MODULE} NT2_CURRENT_MODULE_U)

  if(PROJECT_NAME STREQUAL NT2 OR PROJECT_NAME STREQUAL "NT2_${NT2_CURRENT_MODULE_U}")
    string(REGEX REPLACE "^(.*)/[^/]+$" "\\1" ${header}_path ${header})
    install(FILES ${PROJECT_BINARY_DIR}/include/${header}
            DESTINATION include/${${header}_path}
            COMPONENT ${NT2_CURRENT_MODULE}
           )
  endif()
endmacro()

macro(nt2_module_configure_toolbox toolbox is_sys)
  if(NT2_CURRENT_MODULE MATCHES "^boost[.]")
    set(prefix "boost/simd")
  else()
    set(prefix "nt2")
  endif()
  
  set(reduce)
  foreach(component functions constants)
  
    set(postfix)
    if(${is_sys})
      set(postfix ${prefix}/include/${component})
    endif()
    
    nt2_module_postconfigure(gather_includes --ignore impl --ignore details --ignore preprocessed
                                             ${prefix}/toolbox/${toolbox}/${component} ${prefix}/toolbox/${toolbox}/include/${component}
                                             --all ${prefix}/toolbox/${toolbox}/${component}.hpp
                                             ${postfix}
                            )
                            
    list(APPEND reduce ${prefix}/toolbox/${toolbox}/${component}.hpp)
  endforeach()
  
  nt2_module_postconfigure(gather_includes ${reduce}
                                           --all ${prefix}/toolbox/${toolbox}/${toolbox}.hpp
                          )
  
endmacro()

macro(nt2_module_configure_file cmake_file header)
  configure_file(${cmake_file} ${PROJECT_BINARY_DIR}/include/${header})
  nt2_module_install_file(${header})
endmacro()

macro(nt2_module_simd_toolbox name)
  string(TOUPPER ${name} name_U)
  get_directory_property(INCLUDE_DIRECTORIES INCLUDE_DIRECTORIES)
  list(REMOVE_DUPLICATES INCLUDE_DIRECTORIES)
  list(REMOVE_ITEM INCLUDE_DIRECTORIES ${PROJECT_BINARY_DIR}/include)
  foreach(dir ${INCLUDE_DIRECTORIES})
    file(GLOB function_files RELATIVE ${dir}/boost/simd/toolbox/${name}/functions ${dir}/boost/simd/toolbox/${name}/functions/*.hpp)
    foreach(file ${function_files})
      set(already_there)
      foreach(dir2 ${INCLUDE_DIRECTORIES})
        if(EXISTS ${dir2}/nt2/toolbox/${name}/include/functions/${file})
          set(already_there 1)
        endif()
      endforeach()
      if(NOT already_there)
        string(REGEX REPLACE ".hpp" "" file ${file})
        string(TOUPPER ${file} file_U)
        file(WRITE ${PROJECT_BINARY_DIR}/include/nt2/toolbox/${name}/include/functions/${file}.hpp
                   "//==============================================================================\n"
                   "//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II       \n"
                   "//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI       \n"
                   "//                                                                              \n"
                   "//          Distributed under the Boost Software License, Version 1.0.          \n"
                   "//                 See accompanying file LICENSE.txt or copy at                 \n"
                   "//                     http://www.boost.org/LICENSE_1_0.txt                     \n"
                   "//==============================================================================\n"
                   "#ifndef NT2_TOOLBOX_${name_U}_INCLUDE_FUNCTIONS_${file_U}_HPP_INCLUDED\n"
                   "#define NT2_TOOLBOX_${name_U}_INCLUDE_FUNCTIONS_${file_U}_HPP_INCLUDED\n"
                   "\n"
                   "#include <boost/simd/toolbox/${name}/include/functions/${file}.hpp>\n"
                   "\n"
                   "namespace nt2\n"
                   "{\n"
                   "  namespace tag\n"
                   "  {\n"
                   "    using boost::simd::tag::${file}_;\n"
                   "  }\n"
                   "\n"
                   "  using boost::simd::${file};\n"
                   "}\n"
                   "\n"
                   "#endif\n"
            )
      endif()
    endforeach()
    
    file(GLOB constant_files RELATIVE ${dir}/boost/simd/toolbox/${name}/constants ${dir}/boost/simd/toolbox/${name}/constants/*.hpp)
    foreach(file ${constant_files})
    set(already_there)
      foreach(dir2 ${INCLUDE_DIRECTORIES})
        if(EXISTS ${dir2}/nt2/toolbox/${name}/include/constants/${file})
          set(already_there 1)
        endif()
      endforeach()
      if(NOT already_there)
        string(REGEX REPLACE ".hpp" "" file ${file})
        string(TOUPPER ${file} file_U)
        string(LENGTH ${file} len)
        math(EXPR len "${len}-1")
        string(SUBSTRING ${file_U} 0 1 file_1)
        string(SUBSTRING ${file} 1 ${len} file_2)
        set(file_c "${file_1}${file_2}")
        file(WRITE ${PROJECT_BINARY_DIR}/include/nt2/toolbox/${name}/include/constants/${file}.hpp
                   "//==============================================================================\n"
                   "//         Copyright 2003 - 2011   LASMEA UMR 6602 CNRS/Univ. Clermont II       \n"
                   "//         Copyright 2009 - 2011   LRI    UMR 8623 CNRS/Univ Paris Sud XI       \n"
                   "//                                                                              \n"
                   "//          Distributed under the Boost Software License, Version 1.0.          \n"
                   "//                 See accompanying file LICENSE.txt or copy at                 \n"
                   "//                     http://www.boost.org/LICENSE_1_0.txt                     \n"
                   "//==============================================================================\n"
                   "#ifndef NT2_TOOLBOX_${name_U}_INCLUDE_CONSTANTS_${file_U}_HPP_INCLUDED\n"
                   "#define NT2_TOOLBOX_${name_U}_INCLUDE_CONSTANTS_${file_U}_HPP_INCLUDED\n"
                   "\n"
                   "#include <boost/simd/toolbox/${name}/include/constants/${file}.hpp>\n"
                   "\n"
                   "namespace nt2\n"
                   "{\n"
                   "  namespace tag\n"
                   "  {\n"
                   "    using boost::simd::tag::${file_c};\n"
                   "  }\n"
                   "\n"
                   "  using boost::simd::${file_c};\n"
                   "}\n"
                   "\n"
                   "#endif\n"
            )
      endif()
    endforeach()
    
    file(GLOB include_files1 RELATIVE ${dir}/boost/simd/toolbox/${name}/include/functions ${dir}/boost/simd/toolbox/${name}/include/functions/*.hpp)
    foreach(file ${include_files1})
      file(READ ${dir}/boost/simd/toolbox/${name}/include/functions/${file} file_content)
      string(REPLACE "boost/simd/" "nt2/" file_content ${file_content})
      string(REPLACE "BOOST_SIMD_" "NT2_" file_content ${file_content})
      file(WRITE ${PROJECT_BINARY_DIR}/include/nt2/toolbox/${name}/include/functions/${file} ${file_content})
    endforeach()
  
    file(GLOB include_files2 RELATIVE ${dir}/boost/simd/toolbox/${name}/include/constants ${dir}/boost/simd/toolbox/${name}/include/constants/*.hpp)
    foreach(file ${include_files2})
      file(READ ${dir}/boost/simd/toolbox/${name}/include/constants/${file} file_content)
      string(REPLACE "boost/simd/" "nt2/" file_content ${file_content})
      string(REPLACE "BOOST_SIMD_" "NT2_" file_content ${file_content})
      file(WRITE ${PROJECT_BINARY_DIR}/include/nt2/toolbox/${name}/include/constants/${file} ${file_content})
    endforeach()
  endforeach()
    
  nt2_module_configure_toolbox(${name} 1)
endmacro()

macro(nt2_module_tool_setup tool)

  get_property(NT2_TOOL_${tool}_BUILT GLOBAL PROPERTY NT2_TOOL_${tool}_BUILT)
  if(NOT NT2_TOOL_${tool}_BUILT)

    define_property(GLOBAL PROPERTY NT2_TOOL_${tool}_BUILT
                    BRIEF_DOCS "Whether nt2 tool ${tool} has already been built"
                    FULL_DOCS "Global flag to avoid building nt2 tool ${tool} multiple times"
                   )
    set_property(GLOBAL PROPERTY NT2_TOOL_${tool}_BUILT 1)

    message(STATUS "[nt2] building tool ${tool}")
    file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/tools/${tool})
  
    execute_process(COMMAND ${CMAKE_COMMAND}
                            -DCMAKE_BUILD_TYPE=Release
                            -G ${CMAKE_GENERATOR}
                            ${NT2_SOURCE_ROOT}/tools/${tool}
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/tools/${tool}
                    OUTPUT_VARIABLE tool_configure_out
                    RESULT_VARIABLE tool_configure
                   )

    if(tool_configure)
      message("${tool_configure_out}")
      message(FATAL_ERROR "[nt2] configuring tool ${tool} failed")
    endif()

    execute_process(COMMAND ${CMAKE_COMMAND} --build . --config Release
                    WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/tools/${tool}
                    OUTPUT_VARIABLE tool_build_out
                    RESULT_VARIABLE tool_build
                   )
                 
    if(tool_build)
      message("${tool_build_out}")
      message(FATAL_ERROR "[nt2] building tool ${tool} failed")
    endif()

    if(PROJECT_NAME STREQUAL NT2 OR PROJECT_NAME STREQUAL "NT2_${NT2_CURRENT_MODULE_U}")
      install( FILES ${PROJECT_BINARY_DIR}/tools/${tool}/${tool}${CMAKE_EXECUTABLE_SUFFIX}
               DESTINATION tools/${tool}
               COMPONENT tools
             )
    endif()

  endif()

endmacro()

macro(nt2_module_tool tool)

  nt2_module_tool_setup(${tool})
  execute_process(COMMAND ${PROJECT_BINARY_DIR}/tools/${tool}/${tool} ${ARGN})

endmacro()

macro(nt2_module_postconfigure)

  string(REPLACE ";" " " args "${ARGN}")
  file(APPEND ${PROJECT_BINARY_DIR}/modules/${NT2_CURRENT_MODULE}.manifest "${args}\n")

endmacro()

macro(nt2_postconfigure_init)

  define_property(GLOBAL PROPERTY NT2_POSTCONFIGURE_INITED
                  BRIEF_DOCS "Whether nt2_postconfigure_init has already been called"
                  FULL_DOCS "Global flag to avoid running postconfigure multiple times"
                 )
  set_property(GLOBAL PROPERTY NT2_POSTCONFIGURE_INITED 1)
  set(NT2_FOUND_COMPONENTS "" CACHE INTERNAL "" FORCE)

  # remove all generated include files at the beginning of configure.
  file(REMOVE_RECURSE ${PROJECT_BINARY_DIR}/include)

  if(PROJECT_NAME STREQUAL NT2 OR PROJECT_NAME STREQUAL "NT2_${NT2_CURRENT_MODULE_U}")
    set(CPACK_NSIS_EXTRA_INSTALL_COMMANDS "ExecWait '\\\"$INSTDIR\\\\tools\\\\postconfigure\\\\postconfigure.exe\\\" \\\"$INSTDIR\\\"'")
    include(CPack)
    cpack_add_component(tools REQUIRED)

    # postconfigure is a target because it's only required to install, not to configure
    file(MAKE_DIRECTORY ${PROJECT_BINARY_DIR}/tools/postconfigure)
    install( FILES ${PROJECT_BINARY_DIR}/tools/postconfigure/postconfigure${CMAKE_EXECUTABLE_SUFFIX}
             DESTINATION tools/postconfigure
             COMPONENT tools
           )
             
    add_custom_target(postconfigure
                      COMMAND ${CMAKE_COMMAND}
                              -DCMAKE_BUILD_TYPE=Release
                              -G ${CMAKE_GENERATOR}
                              ${NT2_SOURCE_ROOT}/tools/postconfigure
                           && ${CMAKE_COMMAND} --build . --config Release
                      WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/tools/postconfigure
                     )
  endif()

endmacro()

macro(nt2_postconfigure_run)

  foreach(module ${NT2_FOUND_COMPONENTS})
    string(TOUPPER ${module} module_U)
    if(NT2_${module_U}_ROOT)
      list(APPEND postconfigure_prefix "-I${NT2_${module_U}_ROOT}/include")
    endif()
  endforeach()
  list(APPEND postconfigure_prefix "${PROJECT_BINARY_DIR}/include")

  foreach(module ${NT2_FOUND_COMPONENTS})
    if(EXISTS ${PROJECT_BINARY_DIR}/modules/${module}.manifest)
      set(file "${PROJECT_BINARY_DIR}/modules/${module}.manifest")
    else()
      set(file "${NT2_ROOT}/modules/${module}.manifest")
    endif()
  
    file(STRINGS ${file} commands)
    foreach(command ${commands})
      string(REGEX REPLACE "^([^ ]+) (.*)$" "\\1" tool ${command})
      string(REGEX REPLACE "^([^ ]+) (.*)$" "\\2" args ${command})
      string(REPLACE " " ";" args ${args})

      nt2_module_tool(${tool} ${postconfigure_prefix} ${args})

    endforeach()
  endforeach()

  if(PROJECT_NAME STREQUAL NT2 OR PROJECT_NAME STREQUAL "NT2_${NT2_CURRENT_MODULE_U}")

    cpack_add_component(postconfigured
                        HIDDEN DISABLED
                       )
  
    install( DIRECTORY ${PROJECT_BINARY_DIR}/include/
             DESTINATION include
             COMPONENT postconfigured
             FILES_MATCHING PATTERN "*.hpp"
           )

  endif()

endmacro()
