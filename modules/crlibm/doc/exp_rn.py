[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '1',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'T',
            },
         'simd_types' : [],
         'special' : ['crlibm'],
         'type_defs' : [],
         'types' : ['real_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 02/03/2011',
             'included' : ['#include <nt2/include/functions/exp.hpp>'],
             'notes' : [],
             'stamp' : 'modified by jt the 02/03/2011',
            },
         'ranges' : {
             'default' : [['T(-706)', 'T(700)']],
             'float'   : [['T(-85)', 'T(85)']],   
            },
         'specific_values' : {
            },
         'verif_test' : {
             'property_call' : {
                 'default' : ['nt2::crlibm::exp_rn(a0)'],
                },
             'property_value' : {
                 'default' : ['nt2::exp(a0)'],
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
