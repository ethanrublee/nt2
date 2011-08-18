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
         'special' : ['trigonometric'],
         'tpl'   : '<nt2::medium>',   
         'type_defs' : [],
         'types' : ['real_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 11/02/2011',
             'included' : ['#include <nt2/toolbox/trigonometric/constants.hpp>',
                           'extern "C" {extern long double cephes_sinl(long double);}'],
             'notes' : [],
             'stamp' : 'modified by jt the 11/02/2011',
            },
         'ranges' : {
             'real_' : [['-nt2::Pi<T>()/4', 'nt2::Pi<T>()/4']],
             'default' : [['-nt2::Pi<T>()/4', 'nt2::Pi<T>()/4']],
            },
         'specific_values' : {
             'default' : {
                 'nt2::Zero<T>()' : {'result' : 'nt2::Zero<r_t>()','ulp_thresh' : '0.5',},
                },
             'real_' : {
                 '-nt2::Pi<T>()/T(2)' : {'result' : 'nt2::Mone<r_t>()','ulp_thresh' : '0.5',},
                 '-nt2::Pi<T>()/T(4)' : {'result' : '-nt2::Sqrt_2o_2<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Inf<T>()' : {'result' : 'nt2::Nan<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Minf<T>()' : {'result' : 'nt2::Nan<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Nan<T>()' : {'result' : 'nt2::Nan<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Pi<T>()/T(2)' : {'result' : 'nt2::One<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Pi<T>()/T(4)' : {'result' : 'nt2::Sqrt_2o_2<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Zero<T>()' : {'result' : 'nt2::Zero<r_t>()','ulp_thresh' : '0.5',},
                },
             'signed_int_' : {
                 'nt2::Zero<T>()' : {'result' : 'nt2::Zero<r_t>()','ulp_thresh' : '0.5',},
                },
            },
         'verif_test' : {
             'property_call' : {
                 'real_' : ['nt2::sine<nt2::medium>(a0)'],
                },
             'property_value' : {
                 'real_' : ['::cephes_sinl(a0)'],
                },
             'ulp_thresh' : {
                 'real_' : ['0.5'],
                },
            },
        },
    },
]
