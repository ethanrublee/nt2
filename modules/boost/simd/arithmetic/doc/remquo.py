[ ## this file was manually modified by jt
    {
     'functor' : {
         'module' : 'boost',
         'arity' : '2',
         'call_types' : [],
         'ret_arity' : '2',
         'rturn' : {
             'default' : 'boost::fusion::tuple<T,typename boost::dispatch::meta::as_integer<T,signed>::type>',
            },
         'simd_types' : ['real_'],
         'type_defs' : [],
         'types' : ['real_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'modified by jt the 01/12/2010',
             'included' : 
                ['#include <boost/fusion/tuple.hpp>',
                 '#include <boost/simd/include/functions/remainder.hpp>',
                 '#include <boost/simd/include/functions/idivround.hpp>'],
             'notes' : [],
             'stamp' : 'modified by jt the 13/12/2010',
            },
         'ranges' : {
             'real_' : [['T(0)', 'T(10)'], ['T(0)', 'T(10)']],
             'signed_int_' : [['-100', '100'], ['-100', '100']],
             'default' : [['0', '100'], ['0', '100']],
            },
         'specific_values' : {
            },
         'verif_test' : {
             'property_call' : {
                 'real_' : ['boost::simd::remquo(a0,a1)'],
                },
             'property_value' : {
                 'real_' : [['boost::simd::remainder(a0,a1)', 'boost::simd::idivround(a0,a1)']],
                },
             'ulp_thresh' : {
                 'real_' : ['0'],
                },
            },
        },
     'version' : '0.1',
    },
]
