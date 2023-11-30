// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_UINT64_COMM_DATALAYER_H_
#define FLATBUFFERS_GENERATED_UINT64_COMM_DATALAYER_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 1 &&
              FLATBUFFERS_VERSION_REVISION == 4,
             "Non-compatible flatbuffers version included");

namespace comm {
namespace datalayer {

struct UInt64;
struct UInt64Builder;
struct UInt64T;

struct UInt64T : public ::flatbuffers::NativeTable {
  typedef UInt64 TableType;
  uint64_t value = 0;
};

struct UInt64 FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef UInt64T NativeTableType;
  typedef UInt64Builder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_VALUE = 4
  };
  uint64_t value() const {
    return GetField<uint64_t>(VT_VALUE, 0);
  }
  bool mutate_value(uint64_t _value = 0) {
    return SetField<uint64_t>(VT_VALUE, _value, 0);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint64_t>(verifier, VT_VALUE, 8) &&
           verifier.EndTable();
  }
  UInt64T *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(UInt64T *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<UInt64> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const UInt64T* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct UInt64Builder {
  typedef UInt64 Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_value(uint64_t value) {
    fbb_.AddElement<uint64_t>(UInt64::VT_VALUE, value, 0);
  }
  explicit UInt64Builder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<UInt64> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<UInt64>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<UInt64> CreateUInt64(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t value = 0) {
  UInt64Builder builder_(_fbb);
  builder_.add_value(value);
  return builder_.Finish();
}

::flatbuffers::Offset<UInt64> CreateUInt64(::flatbuffers::FlatBufferBuilder &_fbb, const UInt64T *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline UInt64T *UInt64::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<UInt64T>(new UInt64T());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void UInt64::UnPackTo(UInt64T *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = value(); _o->value = _e; }
}

inline ::flatbuffers::Offset<UInt64> UInt64::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const UInt64T* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateUInt64(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<UInt64> CreateUInt64(::flatbuffers::FlatBufferBuilder &_fbb, const UInt64T *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const UInt64T* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _value = _o->value;
  return comm::datalayer::CreateUInt64(
      _fbb,
      _value);
}

inline const comm::datalayer::UInt64 *GetUInt64(const void *buf) {
  return ::flatbuffers::GetRoot<comm::datalayer::UInt64>(buf);
}

inline const comm::datalayer::UInt64 *GetSizePrefixedUInt64(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<comm::datalayer::UInt64>(buf);
}

inline UInt64 *GetMutableUInt64(void *buf) {
  return ::flatbuffers::GetMutableRoot<UInt64>(buf);
}

inline comm::datalayer::UInt64 *GetMutableSizePrefixedUInt64(void *buf) {
  return ::flatbuffers::GetMutableSizePrefixedRoot<comm::datalayer::UInt64>(buf);
}

inline bool VerifyUInt64Buffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<comm::datalayer::UInt64>(nullptr);
}

inline bool VerifySizePrefixedUInt64Buffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<comm::datalayer::UInt64>(nullptr);
}

inline void FinishUInt64Buffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<comm::datalayer::UInt64> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedUInt64Buffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<comm::datalayer::UInt64> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<comm::datalayer::UInt64T> UnPackUInt64(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::UInt64T>(GetUInt64(buf)->UnPack(res));
}

inline std::unique_ptr<comm::datalayer::UInt64T> UnPackSizePrefixedUInt64(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::UInt64T>(GetSizePrefixedUInt64(buf)->UnPack(res));
}

}  // namespace datalayer
}  // namespace comm

#endif  // FLATBUFFERS_GENERATED_UINT64_COMM_DATALAYER_H_
