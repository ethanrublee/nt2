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
         'special' : ['cephes'],
         'type_defs' : [],
         'types' : ['real_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 01/03/2011',
             'included' : ['#include <nt2/include/functions/sqrt.hpp>'],
             'notes' : [],
             'stamp' : 'modified by jt the 01/03/2011',
            },
         'ranges' : {
             'default' : [['T(0)', 'T(100)']],
            },
         'specific_values' : {
             'default' : {
                },
             'real_' : {
                 'nt2::One<T>()' : 'nt2::One<r_t>()',
                 'nt2::Zero<T>()' : 'nt2::Zero<r_t>()',
                 'nt2::Four<T>()' : 'nt2::Two<r_t>()',   
                },
             'signed_int_' : {
                 'nt2::One<T>()' : 'nt2::One<r_t>()',
                 'nt2::Zero<T>()' : 'nt2::Zero<r_t>()',
                 'nt2::Four<T>()' : 'nt2::Two<r_t>()',   
                },
             'unsigned_int_' : {
                 'nt2::One<T>()' : 'nt2::One<r_t>()',
                 'nt2::Zero<T>()' : 'nt2::Zero<r_t>()',
                 'nt2::Four<T>()' : 'nt2::Two<r_t>()',   
                },            },
         'verif_test' : {
             'property_call' : {
                 'default' : ['nt2::cephes::sqrt(a0)'],
                },
             'property_value' : {
                 'default' : ['nt2::sqrt(a0)'],
                },
             'simd' : {
                },
             'ulp_thresh' : {
                 'default' : ['0.5'],
                },
            },
        },
    },
]
