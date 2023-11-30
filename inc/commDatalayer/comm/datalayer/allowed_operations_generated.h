// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_ALLOWEDOPERATIONS_COMM_DATALAYER_H_
#define FLATBUFFERS_GENERATED_ALLOWEDOPERATIONS_COMM_DATALAYER_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 1 &&
              FLATBUFFERS_VERSION_REVISION == 4,
             "Non-compatible flatbuffers version included");

namespace comm {
namespace datalayer {

struct AllowedOperations;
struct AllowedOperationsBuilder;
struct AllowedOperationsT;

struct AllowedOperationsT : public ::flatbuffers::NativeTable {
  typedef AllowedOperations TableType;
  bool read = false;
  bool write = false;
  bool create = false;
  bool delete_ = false;
  bool browse = true;
};

struct AllowedOperations FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef AllowedOperationsT NativeTableType;
  typedef AllowedOperationsBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_READ = 4,
    VT_WRITE = 6,
    VT_CREATE = 8,
    VT_DELETE_ = 10,
    VT_BROWSE = 12
  };
  /// get
  bool read() const {
    return GetField<uint8_t>(VT_READ, 0) != 0;
  }
  bool mutate_read(bool _read = 0) {
    return SetField<uint8_t>(VT_READ, static_cast<uint8_t>(_read), 0);
  }
  /// put
  bool write() const {
    return GetField<uint8_t>(VT_WRITE, 0) != 0;
  }
  bool mutate_write(bool _write = 0) {
    return SetField<uint8_t>(VT_WRITE, static_cast<uint8_t>(_write), 0);
  }
  /// post
  bool create() const {
    return GetField<uint8_t>(VT_CREATE, 0) != 0;
  }
  bool mutate_create(bool _create = 0) {
    return SetField<uint8_t>(VT_CREATE, static_cast<uint8_t>(_create), 0);
  }
  /// delete
  bool delete_() const {
    return GetField<uint8_t>(VT_DELETE_, 0) != 0;
  }
  bool mutate_delete_(bool _delete_ = 0) {
    return SetField<uint8_t>(VT_DELETE_, static_cast<uint8_t>(_delete_), 0);
  }
  /// browse
  bool browse() const {
    return GetField<uint8_t>(VT_BROWSE, 1) != 0;
  }
  bool mutate_browse(bool _browse = 1) {
    return SetField<uint8_t>(VT_BROWSE, static_cast<uint8_t>(_browse), 1);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint8_t>(verifier, VT_READ, 1) &&
           VerifyField<uint8_t>(verifier, VT_WRITE, 1) &&
           VerifyField<uint8_t>(verifier, VT_CREATE, 1) &&
           VerifyField<uint8_t>(verifier, VT_DELETE_, 1) &&
           VerifyField<uint8_t>(verifier, VT_BROWSE, 1) &&
           verifier.EndTable();
  }
  AllowedOperationsT *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(AllowedOperationsT *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<AllowedOperations> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const AllowedOperationsT* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct AllowedOperationsBuilder {
  typedef AllowedOperations Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_read(bool read) {
    fbb_.AddElement<uint8_t>(AllowedOperations::VT_READ, static_cast<uint8_t>(read), 0);
  }
  void add_write(bool write) {
    fbb_.AddElement<uint8_t>(AllowedOperations::VT_WRITE, static_cast<uint8_t>(write), 0);
  }
  void add_create(bool create) {
    fbb_.AddElement<uint8_t>(AllowedOperations::VT_CREATE, static_cast<uint8_t>(create), 0);
  }
  void add_delete_(bool delete_) {
    fbb_.AddElement<uint8_t>(AllowedOperations::VT_DELETE_, static_cast<uint8_t>(delete_), 0);
  }
  void add_browse(bool browse) {
    fbb_.AddElement<uint8_t>(AllowedOperations::VT_BROWSE, static_cast<uint8_t>(browse), 1);
  }
  explicit AllowedOperationsBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<AllowedOperations> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<AllowedOperations>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<AllowedOperations> CreateAllowedOperations(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    bool read = false,
    bool write = false,
    bool create = false,
    bool delete_ = false,
    bool browse = true) {
  AllowedOperationsBuilder builder_(_fbb);
  builder_.add_browse(browse);
  builder_.add_delete_(delete_);
  builder_.add_create(create);
  builder_.add_write(write);
  builder_.add_read(read);
  return builder_.Finish();
}

::flatbuffers::Offset<AllowedOperations> CreateAllowedOperations(::flatbuffers::FlatBufferBuilder &_fbb, const AllowedOperationsT *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline AllowedOperationsT *AllowedOperations::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<AllowedOperationsT>(new AllowedOperationsT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void AllowedOperations::UnPackTo(AllowedOperationsT *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = read(); _o->read = _e; }
  { auto _e = write(); _o->write = _e; }
  { auto _e = create(); _o->create = _e; }
  { auto _e = delete_(); _o->delete_ = _e; }
  { auto _e = browse(); _o->browse = _e; }
}

inline ::flatbuffers::Offset<AllowedOperations> AllowedOperations::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const AllowedOperationsT* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateAllowedOperations(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<AllowedOperations> CreateAllowedOperations(::flatbuffers::FlatBufferBuilder &_fbb, const AllowedOperationsT *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const AllowedOperationsT* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _read = _o->read;
  auto _write = _o->write;
  auto _create = _o->create;
  auto _delete_ = _o->delete_;
  auto _browse = _o->browse;
  return comm::datalayer::CreateAllowedOperations(
      _fbb,
      _read,
      _write,
      _create,
      _delete_,
      _browse);
}

inline const comm::datalayer::AllowedOperations *GetAllowedOperations(const void *buf) {
  return ::flatbuffers::GetRoot<comm::datalayer::AllowedOperations>(buf);
}

inline const comm::datalayer::AllowedOperations *GetSizePrefixedAllowedOperations(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<comm::datalayer::AllowedOperations>(buf);
}

inline AllowedOperations *GetMutableAllowedOperations(void *buf) {
  return ::flatbuffers::GetMutableRoot<AllowedOperations>(buf);
}

inline comm::datalayer::AllowedOperations *GetMutableSizePrefixedAllowedOperations(void *buf) {
  return ::flatbuffers::GetMutableSizePrefixedRoot<comm::datalayer::AllowedOperations>(buf);
}

inline bool VerifyAllowedOperationsBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<comm::datalayer::AllowedOperations>(nullptr);
}

inline bool VerifySizePrefixedAllowedOperationsBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<comm::datalayer::AllowedOperations>(nullptr);
}

inline void FinishAllowedOperationsBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<comm::datalayer::AllowedOperations> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedAllowedOperationsBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<comm::datalayer::AllowedOperations> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<comm::datalayer::AllowedOperationsT> UnPackAllowedOperations(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::AllowedOperationsT>(GetAllowedOperations(buf)->UnPack(res));
}

inline std::unique_ptr<comm::datalayer::AllowedOperationsT> UnPackSizePrefixedAllowedOperations(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::AllowedOperationsT>(GetSizePrefixedAllowedOperations(buf)->UnPack(res));
}

}  // namespace datalayer
}  // namespace comm

#endif  // FLATBUFFERS_GENERATED_ALLOWEDOPERATIONS_COMM_DATALAYER_H_
