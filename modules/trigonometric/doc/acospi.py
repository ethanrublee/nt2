[ ## this file was manually modified by jt
    {
     'functor' : {
         'arity' : '1',
         'call_types' : [],
         'ret_arity' : '0',
         'rturn' : {
             'default' : 'typename boost::result_of<nt2::meta::floating(T)>::type',
            },
         'simd_types' : ['real_','int_convert_','uint_convert_'],
         'special' : ['trigonometric'],
         'type_defs' : ['static const long double long_pi = 3.141592653589793238462643383279502884197l;'],
         'types' : ['real_', 'unsigned_int_', 'signed_int_'],
         'simd_types' : ['real_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 11/02/2011',
             'included' : ['#include <nt2/toolbox/trigonometric/constants.hpp>',
                           'extern "C" {extern long double cephes_acosl(long double);}'],
            'notes' : [],
             'stamp' : 'modified by jt the 11/02/2011',
            },
         'ranges' : {
             'default' : [['nt2::Zero<T>()', 'nt2::One<T>()']],
             'real_' : [['nt2::Mone<T>()', 'nt2::One<T>()']],
             'signed_int_' : [['T(-1)', 'T(1)']],
            },
         'specific_values' : {
             'default' : {
                 'nt2::One<T>()' : {'result' : '0','ulp_thresh' : '0.5',},
                 'nt2::Zero<T>()' : {'result' : '0.5','ulp_thresh' : '0.5',},
                },
             'real_' : {
                 'nt2::Half<T>()' : {'result' : 'T(1)/3','ulp_thresh' : '0.5',},
                 'nt2::Mhalf<T>()' : {'result' : 'T(2)/3','ulp_thresh' : '0.5',},
                 'nt2::Mone<T>()' : {'result' : '1','ulp_thresh' : '0.5',},
                 'nt2::Nan<T>()' : {'result' : 'nt2::Nan<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::One<T>()' : {'result' : '0','ulp_thresh' : '0.5',},
                 'nt2::Zero<T>()' : {'result' : '0.5','ulp_thresh' : '0.5',},
                },
             'signed_int_' : {
                 'nt2::Mone<T>()' : {'result' : '1','ulp_thresh' : '0.5',},
                 'nt2::One<T>()' : {'result' : '0','ulp_thresh' : '0.5',},
                 'nt2::Zero<T>()' : {'result' : '0.5','ulp_thresh' : '0.5',},
                },
            },
         'verif_test' : {
             'property_call' : {
                 'real_' : ['nt2::acospi(a0)'],
                },
             'property_value' : {
                 'real_' : ['::cephes_acosl(a0)/long_pi'],
                },
             'ulp_thresh' : {
                 'real_' : '1.0',
                },
            },
        },
    },
]
