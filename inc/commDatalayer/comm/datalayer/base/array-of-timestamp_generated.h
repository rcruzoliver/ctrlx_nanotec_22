// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_ARRAYOFTIMESTAMP_COMM_DATALAYER_H_
#define FLATBUFFERS_GENERATED_ARRAYOFTIMESTAMP_COMM_DATALAYER_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 1 &&
              FLATBUFFERS_VERSION_REVISION == 4,
             "Non-compatible flatbuffers version included");

namespace comm {
namespace datalayer {

struct ArrayOfTimestamp;
struct ArrayOfTimestampBuilder;
struct ArrayOfTimestampT;

struct ArrayOfTimestampT : public ::flatbuffers::NativeTable {
  typedef ArrayOfTimestamp TableType;
  std::vector<uint64_t> value{};
};

struct ArrayOfTimestamp FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef ArrayOfTimestampT NativeTableType;
  typedef ArrayOfTimestampBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_VALUE = 4
  };
  const ::flatbuffers::Vector<uint64_t> *value() const {
    return GetPointer<const ::flatbuffers::Vector<uint64_t> *>(VT_VALUE);
  }
  ::flatbuffers::Vector<uint64_t> *mutable_value() {
    return GetPointer<::flatbuffers::Vector<uint64_t> *>(VT_VALUE);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_VALUE) &&
           verifier.VerifyVector(value()) &&
           verifier.EndTable();
  }
  ArrayOfTimestampT *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(ArrayOfTimestampT *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<ArrayOfTimestamp> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const ArrayOfTimestampT* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct ArrayOfTimestampBuilder {
  typedef ArrayOfTimestamp Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_value(::flatbuffers::Offset<::flatbuffers::Vector<uint64_t>> value) {
    fbb_.AddOffset(ArrayOfTimestamp::VT_VALUE, value);
  }
  explicit ArrayOfTimestampBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<ArrayOfTimestamp> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<ArrayOfTimestamp>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<ArrayOfTimestamp> CreateArrayOfTimestamp(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::Vector<uint64_t>> value = 0) {
  ArrayOfTimestampBuilder builder_(_fbb);
  builder_.add_value(value);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<ArrayOfTimestamp> CreateArrayOfTimestampDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<uint64_t> *value = nullptr) {
  auto value__ = value ? _fbb.CreateVector<uint64_t>(*value) : 0;
  return comm::datalayer::CreateArrayOfTimestamp(
      _fbb,
      value__);
}

::flatbuffers::Offset<ArrayOfTimestamp> CreateArrayOfTimestamp(::flatbuffers::FlatBufferBuilder &_fbb, const ArrayOfTimestampT *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline ArrayOfTimestampT *ArrayOfTimestamp::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<ArrayOfTimestampT>(new ArrayOfTimestampT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void ArrayOfTimestamp::UnPackTo(ArrayOfTimestampT *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = value(); if (_e) { _o->value.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->value[_i] = _e->Get(_i); } } else { _o->value.resize(0); } }
}

inline ::flatbuffers::Offset<ArrayOfTimestamp> ArrayOfTimestamp::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const ArrayOfTimestampT* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateArrayOfTimestamp(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<ArrayOfTimestamp> CreateArrayOfTimestamp(::flatbuffers::FlatBufferBuilder &_fbb, const ArrayOfTimestampT *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const ArrayOfTimestampT* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _value = _o->value.size() ? _fbb.CreateVector(_o->value) : 0;
  return comm::datalayer::CreateArrayOfTimestamp(
      _fbb,
      _value);
}

inline const comm::datalayer::ArrayOfTimestamp *GetArrayOfTimestamp(const void *buf) {
  return ::flatbuffers::GetRoot<comm::datalayer::ArrayOfTimestamp>(buf);
}

inline const comm::datalayer::ArrayOfTimestamp *GetSizePrefixedArrayOfTimestamp(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<comm::datalayer::ArrayOfTimestamp>(buf);
}

inline ArrayOfTimestamp *GetMutableArrayOfTimestamp(void *buf) {
  return ::flatbuffers::GetMutableRoot<ArrayOfTimestamp>(buf);
}

inline comm::datalayer::ArrayOfTimestamp *GetMutableSizePrefixedArrayOfTimestamp(void *buf) {
  return ::flatbuffers::GetMutableSizePrefixedRoot<comm::datalayer::ArrayOfTimestamp>(buf);
}

inline bool VerifyArrayOfTimestampBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<comm::datalayer::ArrayOfTimestamp>(nullptr);
}

inline bool VerifySizePrefixedArrayOfTimestampBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<comm::datalayer::ArrayOfTimestamp>(nullptr);
}

inline void FinishArrayOfTimestampBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<comm::datalayer::ArrayOfTimestamp> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedArrayOfTimestampBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<comm::datalayer::ArrayOfTimestamp> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<comm::datalayer::ArrayOfTimestampT> UnPackArrayOfTimestamp(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::ArrayOfTimestampT>(GetArrayOfTimestamp(buf)->UnPack(res));
}

inline std::unique_ptr<comm::datalayer::ArrayOfTimestampT> UnPackSizePrefixedArrayOfTimestamp(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::ArrayOfTimestampT>(GetSizePrefixedArrayOfTimestamp(buf)->UnPack(res));
}

}  // namespace datalayer
}  // namespace comm

#endif  // FLATBUFFERS_GENERATED_ARRAYOFTIMESTAMP_COMM_DATALAYER_H_
