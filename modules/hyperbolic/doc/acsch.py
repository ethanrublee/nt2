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
         'simd_ulp_thresh' : ['1.5'],   
         'type_defs' : [],
         'types' : ['real_', 'unsigned_int_', 'signed_int_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'created  by jt the 20/02/2011',
             'included' : 
                ['#include <nt2/toolbox/exponential/include/constants.hpp>',
                 '#include <nt2/toolbox/boost_math/include/asinh.hpp>',
                           'extern "C" { long double cephes_asinhl(long double); }',
                  '#include <nt2/include/functions/rec.hpp>'],
             'notes' : [],
             'stamp' : 'modified by jt the 20/02/2011',
            },
         'ranges' : {
             'default' : [[['T(1)', 'T(100)']],[['T(-100)', 'T(-1)']]],
             'unsigned_int_' : [[['T(1)', 'T(100)']]],
            },
         'specific_values' : {
             'default' : {
                 'nt2::Zero<T>()' : {'result' : 'nt2::Nan<r_t>()','ulp_thresh' : '0.5',},
                },
             'real_' : {
                 '-nt2::Zero<T>()' : {'result' : 'nt2::Minf<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Inf<T>()' : {'result' : 'nt2::Zero<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Minf<T>()' : {'result' : 'nt2::Zero<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Nan<T>()' : {'result' : 'nt2::Nan<r_t>()','ulp_thresh' : '0.5',},
                 'nt2::Zero<T>()' : {'result' : 'nt2::Inf<r_t>()','ulp_thresh' : '0.5',},
                },
             'signed_int_   ' : {
                 'nt2::Zero<T>()' : {'result' : 'nt2::Nan<r_t>()','ulp_thresh' : '0.5',},
                },
            },
         'verif_test' : {
             'property_call' : {
                 'real_' : ['nt2::acsch(a0)','nt2::acsch(a0)'],
                },
             'property_value' : {
                 'real_' : ['nt2::boost_math::asinh(nt2::rec(a0))','::cephes_asinhl(nt2::rec(a0))'],
                },
             'ulp_thresh' : {
                 'real_' : ['1.5'],
                },
            },
        },
    },
]
