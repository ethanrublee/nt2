[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '1',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'typename boost::result_of<nt2::meta::floating(T)>::type',
            },
         'simd_types' : ['real_'],
         'type_defs' : [],
         'types' : ['real_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 21/02/2011',
             'included' : ['extern "C" {long double cephes_ellpel(long double);}'],
             'notes' : [],
             'stamp' : 'modified by jt the 21/02/2011',
            },
         'ranges' : {
             'real_' : [['T(0)', 'T(1)']],
            },
         'specific_values' : {
             'real_' : {
                 'nt2::One<T>()' : {'result' : 'nt2::Pio_2<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Pio_2<T>()' : {'result' : 'nt2::Nan<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Zero<T>()' : {'result' : 'nt2::One<r_t>()','ulp_thresh' : '0.5',},
                },
            },
         'verif_test' : {
             'nb_rand' : {
                 'default' : 'NT2_NB_RANDOM_TEST',
                },
             'property_call' : {
                 'default' : ['nt2::ellpe(a0)'],
                },
             'property_value' : {
                 'default' : ['::cephes_ellpel(a0)'],
                },
             'ulp_thresh' : {
                 'default' : ['1.0'],
                },
            },
        },
    },
]
