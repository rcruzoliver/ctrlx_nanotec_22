// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_ARRAYOFDOUBLE_COMM_DATALAYER_H_
#define FLATBUFFERS_GENERATED_ARRAYOFDOUBLE_COMM_DATALAYER_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 1 &&
              FLATBUFFERS_VERSION_REVISION == 4,
             "Non-compatible flatbuffers version included");

namespace comm {
namespace datalayer {

struct ArrayOfDouble;
struct ArrayOfDoubleBuilder;
struct ArrayOfDoubleT;

struct ArrayOfDoubleT : public ::flatbuffers::NativeTable {
  typedef ArrayOfDouble TableType;
  std::vector<double> value{};
};

struct ArrayOfDouble FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef ArrayOfDoubleT NativeTableType;
  typedef ArrayOfDoubleBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_VALUE = 4
  };
  const ::flatbuffers::Vector<double> *value() const {
    return GetPointer<const ::flatbuffers::Vector<double> *>(VT_VALUE);
  }
  ::flatbuffers::Vector<double> *mutable_value() {
    return GetPointer<::flatbuffers::Vector<double> *>(VT_VALUE);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_VALUE) &&
           verifier.VerifyVector(value()) &&
           verifier.EndTable();
  }
  ArrayOfDoubleT *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(ArrayOfDoubleT *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<ArrayOfDouble> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const ArrayOfDoubleT* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct ArrayOfDoubleBuilder {
  typedef ArrayOfDouble Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_value(::flatbuffers::Offset<::flatbuffers::Vector<double>> value) {
    fbb_.AddOffset(ArrayOfDouble::VT_VALUE, value);
  }
  explicit ArrayOfDoubleBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<ArrayOfDouble> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<ArrayOfDouble>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<ArrayOfDouble> CreateArrayOfDouble(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::Vector<double>> value = 0) {
  ArrayOfDoubleBuilder builder_(_fbb);
  builder_.add_value(value);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<ArrayOfDouble> CreateArrayOfDoubleDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<double> *value = nullptr) {
  auto value__ = value ? _fbb.CreateVector<double>(*value) : 0;
  return comm::datalayer::CreateArrayOfDouble(
      _fbb,
      value__);
}

::flatbuffers::Offset<ArrayOfDouble> CreateArrayOfDouble(::flatbuffers::FlatBufferBuilder &_fbb, const ArrayOfDoubleT *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline ArrayOfDoubleT *ArrayOfDouble::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<ArrayOfDoubleT>(new ArrayOfDoubleT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void ArrayOfDouble::UnPackTo(ArrayOfDoubleT *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = value(); if (_e) { _o->value.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->value[_i] = _e->Get(_i); } } else { _o->value.resize(0); } }
}

inline ::flatbuffers::Offset<ArrayOfDouble> ArrayOfDouble::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const ArrayOfDoubleT* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateArrayOfDouble(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<ArrayOfDouble> CreateArrayOfDouble(::flatbuffers::FlatBufferBuilder &_fbb, const ArrayOfDoubleT *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const ArrayOfDoubleT* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _value = _o->value.size() ? _fbb.CreateVector(_o->value) : 0;
  return comm::datalayer::CreateArrayOfDouble(
      _fbb,
      _value);
}

inline const comm::datalayer::ArrayOfDouble *GetArrayOfDouble(const void *buf) {
  return ::flatbuffers::GetRoot<comm::datalayer::ArrayOfDouble>(buf);
}

inline const comm::datalayer::ArrayOfDouble *GetSizePrefixedArrayOfDouble(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<comm::datalayer::ArrayOfDouble>(buf);
}

inline ArrayOfDouble *GetMutableArrayOfDouble(void *buf) {
  return ::flatbuffers::GetMutableRoot<ArrayOfDouble>(buf);
}

inline comm::datalayer::ArrayOfDouble *GetMutableSizePrefixedArrayOfDouble(void *buf) {
  return ::flatbuffers::GetMutableSizePrefixedRoot<comm::datalayer::ArrayOfDouble>(buf);
}

inline bool VerifyArrayOfDoubleBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<comm::datalayer::ArrayOfDouble>(nullptr);
}

inline bool VerifySizePrefixedArrayOfDoubleBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<comm::datalayer::ArrayOfDouble>(nullptr);
}

inline void FinishArrayOfDoubleBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<comm::datalayer::ArrayOfDouble> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedArrayOfDoubleBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<comm::datalayer::ArrayOfDouble> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<comm::datalayer::ArrayOfDoubleT> UnPackArrayOfDouble(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::ArrayOfDoubleT>(GetArrayOfDouble(buf)->UnPack(res));
}

inline std::unique_ptr<comm::datalayer::ArrayOfDoubleT> UnPackSizePrefixedArrayOfDouble(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::ArrayOfDoubleT>(GetSizePrefixedArrayOfDouble(buf)->UnPack(res));
}

}  // namespace datalayer
}  // namespace comm

#endif  // FLATBUFFERS_GENERATED_ARRAYOFDOUBLE_COMM_DATALAYER_H_
