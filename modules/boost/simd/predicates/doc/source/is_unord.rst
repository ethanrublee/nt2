.. _is_unord:

is_unord
==========

.. index::
    single: is_unord

Description
^^^^^^^^^^^


Template Parameters
^^^^^^^^^^^^^^^^^^^

  +-----------+-----------------------------------+--------------------+
  | Parameter | Requirement                       | Description        |
  +===========+===================================+====================+
  |           |                                   |                    |
  +-----------+-----------------------------------+--------------------+
  |           |                                   |                    |
  +-----------+-----------------------------------+--------------------+

Header File
^^^^^^^^^^^

This functor belongs to the namespace: ``functors``

.. code-block:: cpp

  #include <nt2/toolbox/predicates/functions/is_unord.hpp>

or simply

.. code-block:: cpp

  #include <nt2/toolbox/predicates.hpp>

for the whole toolbox

Synopsis
^^^^^^^^

.. code-block:: cpp

    <unspecified return type>  is_unord(
                      const A0& a0, const A1& a1
                     );

Expression Semantics
^^^^^^^^^^^^^^^^^^^^

.. code-block:: cpp


**Return type:** an unspecified type

**Semantic:** Equivalent to


Example
^^^^^^^

.. literalinclude:: $self.path2examples2$/examples/src/is_unord.cpp
   :language: cpp
