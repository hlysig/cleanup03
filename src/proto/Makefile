PROTOC = protoc
GRPC_CPP_PLUGIN = grpc_cpp_plugin
GRPC_CPP_PLUGIN_PATH ?= `which $(GRPC_CPP_PLUGIN)`

PROTOS_PATH = .
OUT_PATH = ../core/proto

OUTS = $(OUT_PATH)/OC.pb.cc 

all: $(OUTS)
.PHONY: all

$(OUTS): $(OUT_PATH)/%.pb.cc: %.proto
	$(PROTOC) -I $(PROTOS_PATH) --grpc_out=$(OUT_PATH) --plugin=protoc-gen-grpc=$(GRPC_CPP_PLUGIN_PATH) $<
	$(PROTOC) -I $(PROTOS_PATH) --cpp_out=$(OUT_PATH) $<

clean:
	rm -f *~
	rm -f $(OUT_PATH)/*.h $(OUT_PATH)/*.cc
