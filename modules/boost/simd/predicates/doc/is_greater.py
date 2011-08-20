[ ## this file was manually modified by jt
    {
     'functor' : {
         'module' : 'boost',
         'arity' : '2',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'typename boost::simd::meta::logical<T>::type',
            },
         'special' : ['predicate'],
         'type_defs' : [],
         'types' : ['integer_','real_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 18/02/2011',
             'included' : ['#include <boost/simd/sdk/meta/logical.hpp>'],
             'no_ulp' : 'True',
             'notes' : [],
             'stamp' : 'modified by jt the 18/02/2011',
            },
         'ranges' : {
             'default' : [
                [['boost::simd::Valmin<T>()/2', 'boost::simd::Valmax<T>()/2'], ['boost::simd::Valmin<T>()/2', 'boost::simd::Valmax<T>()/2']],
                ],
            },
         'specific_values' : {
             'default' : {
                 'boost::simd::One<T>()' : {'result' : 'false','ulp_thresh' : '0',},
                 'boost::simd::One<T>(),boost::simd::Zero<T>()' : {'result' : 'true','ulp_thresh' : '0',},
                 'boost::simd::Zero<T>()' : {'result' : 'false','ulp_thresh' : '0',},
                },
             'integer_   ' : {
                 'boost::simd::Mone<T>()' : {'result' : 'false','ulp_thresh' : '0',},
                 'boost::simd::One<T>()' : {'result' : 'false','ulp_thresh' : '0',},
                 'boost::simd::One<T>(),boost::simd::Zero<T>()' : {'result' : 'true','ulp_thresh' : '0',},
                 'boost::simd::Zero<T>()' : {'result' : 'false','ulp_thresh' : '0',},
                },
             'real_' : {
                 'boost::simd::Inf<T>()' : {'result' : 'false','ulp_thresh' : '0',},
                 'boost::simd::Minf<T>()' : {'result' : 'false','ulp_thresh' : '0',},
                 'boost::simd::Nan<T>()' : {'result' : 'false','ulp_thresh' : '0',},
                 'boost::simd::One<T>(),boost::simd::Zero<T>()' : {'result' : 'true','ulp_thresh' : '0',},
                 'boost::simd::Zero<T>()' : {'result' : 'false','ulp_thresh' : '0',},
                },
            },
         'verif_test' : {
             'property_call' : {
                 'integer_' : ['boost::simd::gt(a0,a1)'],
                },
             'property_value' : {
                 'integer_' : ['a0>a1'],
                },
             'simd' : {
                },
             'ulp_thresh' : {
                 'integer_' : ['0'],
                },
            },
        },
    },
]
