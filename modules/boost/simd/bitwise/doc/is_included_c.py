[ ## this file was manually modified by jt
    {
     'functor' : {
         'module' : 'boost',
         'arity' : '2',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'bool',
            },
         'special' : ['reduction'],  
         'type_defs' : [],
         'types' : ['integer_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 18/02/2011',
             'included' : ['#include <boost/simd/include/functions/complement.hpp>'],
             'no_ulp' : 'True',
             'notes' : [],
             'stamp' : 'modified by jt the 12/08/2011',
            },
         'ranges' : {
             'default' : [
                [['boost::simd::Valmin<T>()/2', 'boost::simd::Valmax<T>()/2'], ['boost::simd::Valmin<T>()/2', 'boost::simd::Valmax<T>()/2']],
                ],
            },
         'specific_values' : {
             'integer_' : {
                 'boost::simd::One<T>(),boost::simd::complement(boost::simd::Three<T>())' : {'result' : 'true','ulp_thresh' : '0',},
                 'boost::simd::One<T>(),boost::simd::complement(boost::simd::Mone<T>())' : {'result' : 'true','ulp_thresh' : '0',},
                 'boost::simd::One<T>(),boost::simd::complement(boost::simd::Two<T>())' : {'result' : 'false','ulp_thresh' : '0',},     
                 'boost::simd::Mone<T>(),boost::simd::complement(boost::simd::Zero<T>())' : {'result' : 'false','ulp_thresh' : '0',},
                 'boost::simd::One<T>()' : {'result' : 'false','ulp_thresh' : '0',},
                 'boost::simd::One<T>(),boost::simd::complement(boost::simd::Zero<T>())' : {'result' : 'false','ulp_thresh' : '0',},
                 'boost::simd::Zero<T>()' : {'result' : 'true','ulp_thresh' : '0',},
                },
            },
         'verif_test' : {
             'property_call' : {
                 'integer_' : ['boost::simd::is_included_c(a0,a1)'],
                },
             'property_value' : {
                 'integer_' : ['(~a0)|a1==a1'],
                },
             'simd' : {
                },
             'ulp_thresh' : {
                 'integer_' : ['0'],
                },
             'scalar_simul' :{
                    'default' : [
                        "        bool z = true;",
                        "        for(int i = 0; i< cardinal_of<n_t>::value; ++i)",
                        "        {",
                        "          z = z&&is_included_c(a0[i],a1[i]);",
                        "        }",
                        "        NT2_TEST_EQUAL( v,z);",
                            ]
               },
            },
        },
    },
]
