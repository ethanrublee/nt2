[ ## this file was manually modified by jt
    {
     'functor' : {
         'module' : 'boost',
         'arity' : '1',
         'call_types' : [],
         'ret_arity' : '2',
         'rturn' : {
             'default' : 'boost::fusion::vector<T,typename boost::dispatch::meta::as_integer<T,signed>::type>',
            },
         'simd_types' : ['real_'],
         'type_defs' : [],
         'types' : ['real_'],
        },
     'info' : 'manually modified',
     'unit' : {
         'global_header' : {
             'first_stamp' : 'modified by jt the 04/12/2010',
             'included' : 
                ['#include <boost/simd/include/functions/mantissa.hpp>',
                 '#include <boost/simd/include/functions/exponent.hpp>'],
             'no_ulp' : 'True',
             'notes' : [],
             'stamp' : 'modified by jt the 12/12/2010',
            },
         'ranges' : {
             'real_' : [['T(-10)', 'T(10)']],
             'signed_int_' : [['-100', '100']],
             'unsigned_int_' : [['0', '100']],
            },
         'specific_values' : {
            },
         'verif_test' : {
             'property_call' : {
                 'default' : ['boost::simd::frexp(a0)'],
                },
             'property_value' : {
                 'default' : [['boost::simd::mantissa(a0)/2', 'boost::simd::exponent(a0)+1']],
                },
             'ulp_thresh' : {
                 'default' : ['0'],
                },
            },
        },
     'version' : '0.1',
    },
]
