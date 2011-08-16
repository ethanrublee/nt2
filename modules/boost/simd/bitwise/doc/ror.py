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
         'simd_types' : ['integer_'],
         'type_defs' : [],
         'types' : ['integer_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 18/02/2011',
             'included' : [],
             'no_ulp' : 'True',
             'notes' : [],
             'stamp' : 'modified by jt the 18/02/2011',
            },
         'ranges' : {
             'default' : [['boost::simd::Valmin<T>()/2', 'boost::simd::Valmax<T>()/2'], ['T(0)', 'sizeof(T)*8-1']],
            },
         'specific_values' : {
             'integer_' : {
                 'boost::simd::Mone<T>(),T(1)' : {'result' : 'boost::simd::Mone<T>()','ulp_thresh' : '0.5',},
                 'boost::simd::Mone<T>(),T(5)' : {'result' : 'boost::simd::Mone<T>()','ulp_thresh' : '0.5',},
                 'boost::simd::One<T>(),T(1)' : {'result' : 'r_t(boost::simd::One<T>()<<(sizeof(T)*8-1))','ulp_thresh' : '0.5',},
                 'T(2),T(2)' : {'result' : 'r_t(boost::simd::One<T>()<<(sizeof(T)*8-1))','ulp_thresh' : '0.5',},
                 'boost::simd::Zero<T>(),T(1)' : {'result' : 'boost::simd::Zero<T>()','ulp_thresh' : '0.5',},
                },
            },
         'verif_test' : {
             'property_call' : {
                },
             'property_value' : {
                },
             'simd' : {
                },
             'ulp_thresh' : {
                },
            },
        },
    },
]
