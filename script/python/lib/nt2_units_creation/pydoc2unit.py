#! /usr/bin/env python
# -*- coding: iso-8859-15  -*-
##############################################################################
#         Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
#         Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI
#
#          Distributed under the Boost Software License, Version 1.0
#                 See accompanying file LICENSE.txt or copy at
#                     http://www.boost.org/LICENSE_1_0.txt
##############################################################################


"""unit test generation for a functor
"""
__author__    = "Lapreste Jean-thierry (lapreste@univ-bpclermont.fr)"
__version__   = "$Revision: 1.0 $"
__date__      = "$Date: 2010    $"
__copyright__ = """ Copyright 2003 & onward LASMEA UMR 6602 CNRS/Univ. Clermont II
                    Copyright 2009 & onward LRI    UMR 8623 CNRS/Univ Paris Sud XI"""
__license__   = "Boost Software License, Version 1.0"

import os
import sys
sys.path.insert(0,os.path.join(os.path.dirname(os.path.realpath(__file__)),'..',"utils"))
sys.path.insert(0,os.path.join(os.path.dirname(os.path.realpath(__file__)),'..',"nt2_basics"))
sys.path.insert(0,os.path.join(os.path.dirname(os.path.realpath(__file__)),'..',"nt2_generation"))

from display_utils                   import show
from files_utils                     import write, exist
##from nt2_base_struct                 import Nt2_base_struct
from nt2_tb_props                    import Nt2_tb_props
from nt2_fct_props                   import Nt2_fct_props
from unit_base_gen                   import Base_gen
from unit_global_header_gen          import Global_header_gen
from unit_type_header_gen            import Type_header_test_gen 
from unit_specific_values_gen        import Specific_values_test_gen 
from unit_random_verif_gen           import Random_verif_test_gen
sys.path.pop(0)
sys.path.pop(0)
sys.path.pop(0)
import re
import shutil
from pprint                          import PrettyPrinter


def create_unit(tb_name,fct_name,mode,parts =["verif","values"]) :
    bg = Base_gen(tb_name,fct_name,mode)
    ghg = Global_header_gen(bg)
    r = ghg.get_gen_result()
    if True:#    try :
        dl = bg.get_fct_dict_list()
        for rank, d in enumerate(dl) :
            origin ="types" if mode == 'scalar' else 'simd_types'
            types = bg.recover(origin,d["functor"],["real_convert_"])
            ret_arity = int(d["functor"]["ret_arity"])
            d_unit = d["unit"]
            for typ in types :
                thg = Type_header_test_gen(bg,d,typ,rank)
                r+=thg.get_gen_beg()
                if ("values" in parts) and d_unit.get("specific_values",None) :
                    svt = Specific_values_test_gen(bg,d,typ,ret_arity,mode)
                    r += svt. get_gen_result()
                if ("verif" in parts) and d_unit.get("verif_test",None) :
                    vtg = Random_verif_test_gen(bg,d,typ,mode)
                    r += vtg. get_gen_result()
                r+=thg.get_gen_end()
        return r
##    except :
##        return None

def write_unit(tb_name,fct_name,mode,s,check=False) :
    nfp = Nt2_fct_props(tb_name,fct_name,mode)
    p = nfp.get_fct_unit_path(mode)
    print "write to %s"%p
  ##  write(p,s,check=check,verbose=True)

    
if __name__ == "__main__" :
    tb_name = "trigonometric"
    fcts = Nt2_tb_props(tb_name).get_fcts_list()
    fcts = ["tanpi","tan","cotd","fast_cotd"]
    parts = ["values","verif"]
    for fct in fcts :
        print fct
        r= create_unit(tb_name,fct,'scalar',parts)
        if r is None :
            print('error for %s' % fct)
        else :
            write_unit(tb_name,fct,'scalar',r)
            PrettyPrinter().pprint(r)
