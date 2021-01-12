#ifndef MADS_GRPC_CONVERT
#define MADS_GRPC_CONVERT

#include <string>
#include <grpcpp/grpcpp.h>
#include "MADS.pb.h"
#include "../core/Object.h"
#include "../core/Tag/Tag.h"
#include "../core/TagSet/TagSet.h"

using namespace std;


// Interface class for conversion between protobuf and OC service
class Converter {
public:
  virtual ~Converter() {};

public:
  virtual MADS::Object* ObjectToProto(const ObjectCube::Object* in, MADS::Object* out = NULL) = 0;
  virtual MADS::TagSet* TagSetToProto(const ObjectCube::TagSet* in, MADS::TagSet* out = NULL) = 0;
  virtual MADS::Tag* TagToProto(const ObjectCube::Tag* in, MADS::Tag* out = NULL) = 0;
};


// Implentation class for conversion between protobuf and MADS service
class MADS_gRPC_converter : public Converter {
  ~MADS_gRPC_converter() {};

public:
  MADS::Object* ObjectToProto(const ObjectCube::Object* in, MADS::Object* out = NULL);
  MADS::TagSet *TagSetToProto(const ObjectCube::TagSet *in, MADS::TagSet *out = NULL);
  MADS::Tag *TagToProto(const ObjectCube::Tag *in, MADS::Tag *out = NULL);
};

#endif
