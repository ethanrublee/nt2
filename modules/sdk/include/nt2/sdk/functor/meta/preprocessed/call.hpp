  template<class Tag, class A0, class Site> struct call<Tag(A0),Site> : meta::result_of<functor<Tag,Site>(A0)> {}; template<class Tag, class A0 , class A1, class Site> struct call<Tag(A0 , A1),Site> : meta::result_of<functor<Tag,Site>(A0 , A1)> {}; template<class Tag, class A0 , class A1 , class A2, class Site> struct call<Tag(A0 , A1 , A2),Site> : meta::result_of<functor<Tag,Site>(A0 , A1 , A2)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3, class Site> struct call<Tag(A0 , A1 , A2 , A3),Site> : meta::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3)> {}; template<class Tag, class A0 , class A1 , class A2 , class A3 , class A4, class Site> struct call<Tag(A0 , A1 , A2 , A3 , A4),Site> : meta::result_of<functor<Tag,Site>(A0 , A1 , A2 , A3 , A4)> {};
