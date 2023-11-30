// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_ARRAYOFUINT8_COMM_DATALAYER_H_
#define FLATBUFFERS_GENERATED_ARRAYOFUINT8_COMM_DATALAYER_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 1 &&
              FLATBUFFERS_VERSION_REVISION == 4,
             "Non-compatible flatbuffers version included");

namespace comm {
namespace datalayer {

struct ArrayOfUInt8;
struct ArrayOfUInt8Builder;
struct ArrayOfUInt8T;

struct ArrayOfUInt8T : public ::flatbuffers::NativeTable {
  typedef ArrayOfUInt8 TableType;
  std::vector<uint8_t> value{};
};

struct ArrayOfUInt8 FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef ArrayOfUInt8T NativeTableType;
  typedef ArrayOfUInt8Builder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_VALUE = 4
  };
  const ::flatbuffers::Vector<uint8_t> *value() const {
    return GetPointer<const ::flatbuffers::Vector<uint8_t> *>(VT_VALUE);
  }
  ::flatbuffers::Vector<uint8_t> *mutable_value() {
    return GetPointer<::flatbuffers::Vector<uint8_t> *>(VT_VALUE);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_VALUE) &&
           verifier.VerifyVector(value()) &&
           verifier.EndTable();
  }
  ArrayOfUInt8T *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(ArrayOfUInt8T *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<ArrayOfUInt8> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const ArrayOfUInt8T* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct ArrayOfUInt8Builder {
  typedef ArrayOfUInt8 Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_value(::flatbuffers::Offset<::flatbuffers::Vector<uint8_t>> value) {
    fbb_.AddOffset(ArrayOfUInt8::VT_VALUE, value);
  }
  explicit ArrayOfUInt8Builder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<ArrayOfUInt8> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<ArrayOfUInt8>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<ArrayOfUInt8> CreateArrayOfUInt8(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::Vector<uint8_t>> value = 0) {
  ArrayOfUInt8Builder builder_(_fbb);
  builder_.add_value(value);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<ArrayOfUInt8> CreateArrayOfUInt8Direct(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<uint8_t> *value = nullptr) {
  auto value__ = value ? _fbb.CreateVector<uint8_t>(*value) : 0;
  return comm::datalayer::CreateArrayOfUInt8(
      _fbb,
      value__);
}

::flatbuffers::Offset<ArrayOfUInt8> CreateArrayOfUInt8(::flatbuffers::FlatBufferBuilder &_fbb, const ArrayOfUInt8T *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline ArrayOfUInt8T *ArrayOfUInt8::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<ArrayOfUInt8T>(new ArrayOfUInt8T());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void ArrayOfUInt8::UnPackTo(ArrayOfUInt8T *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = value(); if (_e) { _o->value.resize(_e->size()); std::copy(_e->begin(), _e->end(), _o->value.begin()); } }
}

inline ::flatbuffers::Offset<ArrayOfUInt8> ArrayOfUInt8::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const ArrayOfUInt8T* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateArrayOfUInt8(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<ArrayOfUInt8> CreateArrayOfUInt8(::flatbuffers::FlatBufferBuilder &_fbb, const ArrayOfUInt8T *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const ArrayOfUInt8T* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _value = _o->value.size() ? _fbb.CreateVector(_o->value) : 0;
  return comm::datalayer::CreateArrayOfUInt8(
      _fbb,
      _value);
}

inline const comm::datalayer::ArrayOfUInt8 *GetArrayOfUInt8(const void *buf) {
  return ::flatbuffers::GetRoot<comm::datalayer::ArrayOfUInt8>(buf);
}

inline const comm::datalayer::ArrayOfUInt8 *GetSizePrefixedArrayOfUInt8(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<comm::datalayer::ArrayOfUInt8>(buf);
}

inline ArrayOfUInt8 *GetMutableArrayOfUInt8(void *buf) {
  return ::flatbuffers::GetMutableRoot<ArrayOfUInt8>(buf);
}

inline comm::datalayer::ArrayOfUInt8 *GetMutableSizePrefixedArrayOfUInt8(void *buf) {
  return ::flatbuffers::GetMutableSizePrefixedRoot<comm::datalayer::ArrayOfUInt8>(buf);
}

inline bool VerifyArrayOfUInt8Buffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<comm::datalayer::ArrayOfUInt8>(nullptr);
}

inline bool VerifySizePrefixedArrayOfUInt8Buffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<comm::datalayer::ArrayOfUInt8>(nullptr);
}

inline void FinishArrayOfUInt8Buffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<comm::datalayer::ArrayOfUInt8> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedArrayOfUInt8Buffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<comm::datalayer::ArrayOfUInt8> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<comm::datalayer::ArrayOfUInt8T> UnPackArrayOfUInt8(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::ArrayOfUInt8T>(GetArrayOfUInt8(buf)->UnPack(res));
}

inline std::unique_ptr<comm::datalayer::ArrayOfUInt8T> UnPackSizePrefixedArrayOfUInt8(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::ArrayOfUInt8T>(GetSizePrefixedArrayOfUInt8(buf)->UnPack(res));
}

}  // namespace datalayer
}  // namespace comm

#endif  // FLATBUFFERS_GENERATED_ARRAYOFUINT8_COMM_DATALAYER_H_
