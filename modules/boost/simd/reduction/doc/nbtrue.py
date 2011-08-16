[ ## this file was manually modified by jt
    {
     'functor' : {
         'module' : 'boost',
         'arity' : '1',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'typename boost::dispatch::meta::as_integer<sT>::type',
            },
         'simd_types' : ['real_'],
         'special' : ['reduction'],  
         'type_defs' : ['typedef typename boost::dispatch::meta::scalar_of<T>::type sT;'],
         'types' : ['real_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 24/02/2011',
             'included' : [],
             'notes' : [],
             'stamp' : 'modified by jt the 24/02/2011',
            },
         'ranges' : {
             'default' : [['boost::simd::Valmin<T>()', 'boost::simd::Valmax<T>()']],
             'real_' : [['T(-100)', 'T(100)']],
             'signed_int_' : [],
             'unsigned_int_' : [],
            },
         'specific_values' : {
             'default' : {
                 'boost::simd::One<T>()' : {'result' :  'cardinal_of<vT>::value','ulp_thresh' : '0',},
                 'boost::simd::Zero<T>()' : {'result' : 'boost::simd::Zero<r_t>()::value','ulp_thresh' : '0',},
                },
             'real_' : {
                 'boost::simd::Inf<T>()' : {'result' :  'cardinal_of<vT>::value','ulp_thresh' : '0',},
                 'boost::simd::Minf<T>()' : {'result' : 'cardinal_of<vT>::value','ulp_thresh' : '0',},
                 'boost::simd::Mone<T>()' : {'result' : 'cardinal_of<vT>::value','ulp_thresh' : '0',},
                 'boost::simd::Nan<T>()' : {'result' :  'cardinal_of<vT>::value','ulp_thresh' : '0',},
                 'boost::simd::One<T>()' : {'result' :  'cardinal_of<vT>::value','ulp_thresh' : '0',},
                 'boost::simd::Zero<T>()' : {'result' : 'boost::simd::Zero<r_t>()','ulp_thresh' : '0',},
                },
             'signed_int_' : {
                 'boost::simd::Mone<T>()' : {'result' : 'cardinal_of<vT>::value','ulp_thresh' : '0',},
                 'boost::simd::One<T>()' :  {'result' : 'cardinal_of<vT>::value','ulp_thresh' : '0',},
                 'boost::simd::Zero<T>()' : {'result' : 'boost::simd::Zero<r_t>()','ulp_thresh' : '0',},
                },
            },
         'verif_test' : {
             'nb_rand' : {
                 'default' : 'NT2_NB_RANDOM_TEST',
                },
             'property_call' : {
                 'default' : ['boost::simd::nbtrue(a0)'],
                },
             'property_value' : {
                 'default' : ['a0!=0'],
                },
             'ulp_thresh' : {
                 'default' : ['0'],
                },
             'scalar_simul' :{
                    'default' : [
                        "        T z = a0[0] != 0;",
                        "        for(int i = 1; i< cardinal_of<n_t>::value; ++i)",
                        "        {",
                        "          z+=a0[i] != 0 ;",
                        "        }",
                        "        NT2_TEST_EQUAL( v,z);",
                            ]
               },
            },
        },
    },
]
