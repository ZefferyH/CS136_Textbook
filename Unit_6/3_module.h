// module.h [INTERFACE]

// you must define TRANSPARENT structures
//   in the INTERFACE
// users will be able to see these
struct transparent {
  int t_field;
};

// you must define OPAQUE structures
//   in the IMPLEMENTATION

// in the INTERFACE, you only provide
//   an INCOMPLETE DECLARATION
// this is often safer since it make 
// reverse engineering harder
struct opaque;