[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '3',
         'call_types' : ['T','T','iT'],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'typename nt2::meta::logical<T>::type',
            },
         'simd_types' : ['real_', 'signed_int_', 'unsigned_int_'],
         'special' : ['fuzzy'],
         'type_defs' : [],
         'types' : ['real_', 'signed_int_', 'unsigned_int_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 04/03/2011',
             'included' : ['#include <nt2/sdk/meta/logical.hpp>'],
             'no_ulp' : 'True',
             'notes' : [],
             'stamp' : 'modified by jt the 04/03/2011',
            },
         'ranges' : {
             'real_' : [['T(-10)', 'T(10)'], ['T(-10)', 'T(10)'], ['iT(-10)', 'iT(10)']],
             'signed_int_' : [['T(-10)', 'T(10)'], ['T(-10)', 'T(10)'], ['iT(-10)', 'iT(10)']],
             'unsigned_int_' : [['T(0)', 'T(10)'], ['T(0)', 'T(10)'], ['iT(0)', 'iT(10)']],
            },
         'specific_values' : {
             'default' : {
                 'T(0),T(0),iT(1)' : {'result' : 'nt2::False<r_t>()','ulp_thresh' : '0',},
                 'T(0),T(1),iT(1)' : {'result' : 'nt2::False<r_t>()','ulp_thresh' : '0',},
                },
            },
         'verif_test' : {
             'property_call' : {
                 'default' : ['nt2::definitely_greater(a0,a1,a2)'],
                },
             'property_value' : {
                 'default' : ['nt2::definitely_greater(a0,a1,a2)'],
                },
             'simd' : {
                },
             'ulp_thresh' : {
                 'default' : ['0'],
                },
            },
        },
    },
]
