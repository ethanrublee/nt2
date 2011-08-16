[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '2',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'T',
            },
         'simd_types' : [],
         'special' : ['fdlibm'],
         'type_defs' : [],
         'types' : ['double','float'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 03/03/2011',
             'cover_included' : ['#include <nt2/include/functions/rem.hpp>',
                                 '#include <nt2/include/functions/abs.hpp>',
                                 '#include <nt2/include/functions/idivfix.hpp>',
                                 ],
             'notes' : [],
             'no_ulp' : 'True',
             'stamp' : 'modified by jt the 03/03/2011',
            },
         'ranges' : {
             'default' : [['T(-10)', 'T(10)'], ['T(-10)', 'T(10)']],
            },
         'specific_values' : {
            },
         'verif_test' : {
             'special_call' : [
                    '        T v1 = nt2::abs(nt2::fdlibm::__ieee754_fmod(a0,a1)+a1*(nt2::idivfix(a0, a1))-a0);',
                    '        T v2 = nt2::abs(nt2::rem(a0,a1)+a1*(nt2::idivfix(a0, a1))-a0);',
                    '        NT2_TEST_LESSER_EQUAL(v2, v1); ',
                    ],
             'property_call' : {
                 'default' : ['nt2::fdlibm::__ieee754_fmod(a0,a1)'],
                },
             'property_value' : {
                 'default' : ['nt2::rem(a0,a1)'],
                },
             'simd' : {
                },
             'ulp_thresh' : {
                 'default' : ['128'],
                },
            },
        },
    },
]
