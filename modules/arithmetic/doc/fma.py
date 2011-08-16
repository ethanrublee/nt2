[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '3',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'typename boost::result_of<nt2::meta::arithmetic(T,T,T)>::type',
            },
         'simd_types' : ['real_'],
         'type_defs' : [],
         'types' : ['real_', 'unsigned_int_', 'signed_int_'],
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
             'real_' : [['T(-10)', 'T(10)'], ['T(-10)', 'T(10)'], ['T(-10)', 'T(10)']],
             'signed_int_' : [['-100', '100'], ['-100', '100'], ['-100', '100']],
             'unsigned_int_' : [['0', '100'], ['0', '100'], ['0', '100']],
             'default' : [['0', '100'], ['0', '100'], ['0', '100']],
            },
         'specific_values' : {
             'default' : {
                },
             'real_' : {
                 'nt2::Inf<T>()' : 'nt2::Inf<T>()',
                 'nt2::Minf<T>()' : 'nt2::Nan<T>()',
                 'nt2::Mone<T>()' : 'nt2::Zero<T>()',
                 'nt2::Nan<T>()' : 'nt2::Nan<T>()',
                 'nt2::One<T>()' : 'nt2::Two<T>()',
                 'nt2::Two<T>(),nt2::Two<T>(),nt2::Three<T>()' : 'nt2::Seven<T>()',
                 'nt2::Zero<T>()' : 'nt2::Zero<T>()',
                },
             'signed_int_' : {
                 'nt2::Mone<T>()' : 'nt2::Zero<T>()',
                 'nt2::One<T>()' : 'nt2::Two<T>()',
                 'nt2::Zero<T>()' : 'nt2::Zero<T>()',
                 'nt2::Two<T>(),nt2::Two<T>(),nt2::Three<T>()' : 'nt2::Seven<T>()',
                },
             'unsigned_int_' : {
                 'nt2::One<T>()' : 'nt2::Two<T>()',
                 'nt2::Zero<T>()' : 'nt2::Zero<T>()',
                 'nt2::Two<T>(),nt2::Two<T>(),nt2::Three<T>()' : 'nt2::Seven<T>()',
                },
            },
         'verif_test' : {
             'property_call' : {
                 'default' : ['nt2::fma(a0,a1,a2)'],
                },
             'property_value' : {
                 'default' : ['a0*a1+a2'],
                },
             'ulp_thresh' : {
                 'default' : ['0'],
                },
            },
        },
     'version' : '0.1',
    },
]
