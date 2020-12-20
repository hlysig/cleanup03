#ifndef MADS_GRPC_CONVERT
#define MADS_GRPC_CONVERT

#include <string>
#include <grpcpp/grpcpp.h>
#include "OC.pb.h"
#include "../core/Object.h"
#include "../core/Tag/Tag.h"
#include "../core/TagSet/TagSet.h"

using namespace std;


// Interface class for conversion between protobuf and OC service
class Converter {
public:
  virtual ~Converter() {};

public:
  virtual OC::Object* ObjectToProto(const ObjectCube::Object* in, OC::Object* out = NULL) = 0;
  virtual OC::TagSet* TagSetToProto(const ObjectCube::TagSet* in, OC::TagSet* out = NULL) = 0;
  virtual OC::Tag* TagToProto(const ObjectCube::Tag* in, OC::Tag* out = NULL) = 0;
};


// Implentation class for conversion between protobuf and OC service
class MADS_gRPC_converter : public Converter {
  ~MADS_gRPC_converter() {};

public:
  OC::Object* ObjectToProto(const ObjectCube::Object* in, OC::Object* out = NULL);
  OC::TagSet *TagSetToProto(const ObjectCube::TagSet *in, OC::TagSet *out = NULL);
  OC::Tag *TagToProto(const ObjectCube::Tag *in, OC::Tag *out = NULL);
};

#endif
