[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '2',
         'call_types' : ['iT','T'],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'T',
            },
         'simd_types' : [],
         'special' : ['gsl_specfun'],
         'type_defs' : [],
         'types' : ['real_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 10/03/2011',
             'included' : [],
             'no_ulp' : 'False',
             'notes' : [],
             'stamp' : 'modified by jt the 10/03/2011',
            },
         'ranges' : {
             'default' : [['iT(1)', 'iT(10)'], ['T(1)', 'T(10)']],
            },
         'specific_values' : {
            },
         'verif_test' : {
             'property_call' : {
                 'default' : ['nt2::gsl_specfun::gsl_sf_bessel_kl_scaled(a0,a1)'],
                },
             'property_value' : {
                 'default' : ['nt2::gsl_specfun::gsl_sf_bessel_kl_scaled(a0,a1)'],
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
