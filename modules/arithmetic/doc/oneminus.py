[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '1',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'T',
            },
         'simd_types' : ['real_'],
         'type_defs' : [],
         'types' : ['real_', 'signed_int_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'modified by jt the 01/12/2010',
             'included' : [],
             'notes' : [],
             'stamp' : 'modified by jt the 13/12/2010',
            },
         'ranges' : {
             'real_' : [['T(-10)', 'T(10)']],
             'signed_int_' : [['-100', '100']],
             'default' : [['0', '100']],
            },
         'specific_values' : {
             'default' : {
                },
             'real_' : {
                 'nt2::Inf<T>()' : '-nt2::Inf<r_t>()',
                 'nt2::Minf<T>()' : '-nt2::Minf<r_t>()',
                 'nt2::Mone<T>()' : 'nt2::Two<r_t>()',
                 'nt2::Nan<T>()' : 'nt2::Nan<r_t>()',
                 'nt2::One<T>()' : 'nt2::Zero<r_t>()',
                 'nt2::Zero<T>()' : 'nt2::One<r_t>()',
                },
             'signed_int_' : {
                 'nt2::Mone<T>()' : 'nt2::Two<r_t>()',
                 'nt2::One<T>()' : 'nt2::Zero<r_t>()',
                 'nt2::Zero<T>()' : 'nt2::One<T>()',
                },
            },
         'verif_test' : {
             'property_call' : {
                 'default' : ['nt2::oneminus(a0)'],
                },
             'property_value' : {
                 'default' : ['1-a0'],
                },
             'ulp_thresh' : {
                 'default' : ['0'],
                },
            },
        },
     'version' : '0.1',
    },
]
