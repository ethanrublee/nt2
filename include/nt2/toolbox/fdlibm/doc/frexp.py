[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '1',
         'call_types' : ['T','iT'],
         'ret_arity' : '2',
         'rturn' : {
             'default' : 'T',
            },
         'simd_types' : [],
         'special' : ['fdlibm'],
         'type_defs' : [],
         'types' : ['real_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 03/03/2011',
             'included' : ['#include <nt2/include/functions/frexp.hpp>'],
             'notes' : [],
             'stamp' : 'modified by jt the 03/03/2011',
            },
         'ranges' : {
             'default' : [['T(-10)', 'T(10)']],
            },
         'specific_values' : {
            },
         'verif_test' : {
             'property_call' : {
                 'default' : ['nt2::fdlibm::frexp(a0)'],
                },
             'property_value' : {
                 'default' : ['nt2::frexp(a0)'],
                },
             'simd' : {
                },
             'ulp_thresh' : {
                 'default' : ['1'],
                },
            },
        },
    },
]