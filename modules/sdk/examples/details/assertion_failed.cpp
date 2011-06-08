#define NT2_DEBUG
#define NT2_ASSERTS_AS_EXCEPTIONS
#include <iostream>
#include <nt2/sdk/error/assert.hpp>

using namespace std;

template<class T> T f(T const& v)
{
  NT2_ASSERT_MSG( v > 4, "v is greater than 4" );
  return v;
}

int main(int, char** )
{
  try
  {
    f(1.23456);
  }
  catch( nt2::assert_exception& e )
  {
    cout << e << endl;
  }
}

