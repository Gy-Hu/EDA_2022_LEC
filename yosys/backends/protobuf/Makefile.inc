ifeq ($(ENABLE_PROTOBUF),1)

backends/protobuf/yosys.pb.cc backends/protobuf/yosys.pb.h: misc/yosys.proto
	$(Q) cd misc && protoc --cpp_out "../backends/protobuf" yosys.proto

backends/protobuf/protobuf.cc: backends/protobuf/yosys.pb.h

OBJS += backends/protobuf/protobuf.o backends/protobuf/yosys.pb.o

endif
