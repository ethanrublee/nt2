#ifndef NT2_TOOLBOX_MATLAB_FUNCTION_SIN_HPP_INCLUDED
#define NT2_TOOLBOX_MATLAB_FUNCTION_SIN_HPP_INCLUDED

#include <nt2/toolbox/matlab/function/feval.hpp>
#include <nt2/include/functor.hpp>

namespace nt2
{
    namespace matlab
    {
        struct sin_ {};
        NT2_FUNCTION_IMPLEMENTATION(sin_, sin, 1)
    }
}

namespace nt2 { namespace meta
{
  NT2_FUNCTOR_IMPLEMENTATION( matlab::sin_, tag::cpu_,
			     (A0),
			     (scalar<real_<A0> >)
			      )
  {
    typedef A0 result_type; 
    NT2_FUNCTOR_CALL(1)
      {
	return matlab::feval<typename NT2_RETURN_TYPE(1)::type>("sin", a0);
      }
  };
} }

#endif
