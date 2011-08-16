[ ## this file was manually modified by jt
    {
     'functor' : {
         'module' : 'boost',
         'arity' : '2',
         'call_types' : ['T', 'iT'],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'T',
            },
         'simd_types' : ['unsigned_int_'],
         'type_defs' : ['typedef T r_type;'],
         'types' : ['unsigned_int_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 18/02/2011',
             'included' : ['#include <boost/simd/include/functions/twopower.hpp>'],
             'no_ulp' : 'True',
             'notes' : [],
             'stamp' : 'modified by jt the 18/02/2011',
            },
         'ranges' : {
             'default' : [['boost::simd::Valmin<T>()/2', 'boost::simd::Valmax<T>()/2'], ['T(0)', 'sizeof(T)*8-1']],
            },
         'specific_values' : {
             'unsigned_int_' : {
                 'boost::simd::Mone<T>(),(sizeof(r_type)*8-1)' : {'result' : 'boost::simd::One<r_t>()','ulp_thresh' : '0.5',},
                 'boost::simd::Mone<T>(),(sizeof(r_type)*8-2)' : {'result' : 'boost::simd::Three<r_t>()','ulp_thresh' : '0.5',},
                 'boost::simd::One<T>(),1' : {'result' : 'boost::simd::Zero<r_t>()','ulp_thresh' : '0.5',},
                 'T(2),1' : {'result' : 'boost::simd::One<T>()','ulp_thresh' : '0.5',},
                 'boost::simd::Zero<T>(),1' : {'result' : 'boost::simd::Zero<r_t>()','ulp_thresh' : '0.5',},
                },
            },
         'verif_test' : {
             'property_call' : {
                 'unsigned_int_' : ['boost::simd::shri(a0,a1)'],
                },
             'property_value' : {
                 'unsigned_int_' : ['a0/boost::simd::twopower(a1)'],
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
