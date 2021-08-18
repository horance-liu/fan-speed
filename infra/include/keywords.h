#ifndef H996AEB02_CF8D_4123_8C07_0A231C59F042
#define H996AEB02_CF8D_4123_8C07_0A231C59F042

//////////////////////////////////////////////////////////////////
template <typename T>
struct Role {
    virtual ~Role() {}
};

#define DEF_INTERFACE(type) struct type : Role<type>


//////////////////////////////////////////////////////////////////
#define EXTENDS(...) , __VA_ARGS__
#define IMPLEMENTS(...) EXTENDS(__VA_ARGS__)

//////////////////////////////////////////////////////////////////
#define ROLE(role) get##role()
#define USE_ROLE(role) virtual role& ROLE(role) const = 0
#define HAS_ROLE(role) USE_ROLE(role)

//////////////////////////////////////////////////////////////////
#define IMPL_ROLE(role)                                       \
role& ROLE(role) const override {                             \
   return const_cast<role&>(static_cast<const role&>(*this)); \
}

//////////////////////////////////////////////////////////////////
#define IMPL_ROLE_WITH_TYPE(role, type)                       \
role& ROLE(role) const override {                             \
   return const_cast<type&>(static_cast<const type&>(*this)); \
}

//////////////////////////////////////////////////////////////////
#define IMPL_ROLE_WITH_VAR(role, var)                       \
role& ROLE(role) const override {                             \
   return const_cast<role&>(static_cast<const role&>(var)); \
}

#endif /* H996AEB02_CF8D_4123_8C07_0A231C59F042 */
