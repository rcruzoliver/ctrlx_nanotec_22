// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_SCOPE_COMM_DATALAYER_H_
#define FLATBUFFERS_GENERATED_SCOPE_COMM_DATALAYER_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 1 &&
              FLATBUFFERS_VERSION_REVISION == 4,
             "Non-compatible flatbuffers version included");

namespace comm {
namespace datalayer {

struct Scope;
struct ScopeBuilder;
struct ScopeT;

struct ScopeT : public ::flatbuffers::NativeTable {
  typedef Scope TableType;
  std::string identifier{};
  std::string name{};
  std::string description{};
  std::vector<std::string> permissionsR{};
  std::vector<std::string> permissionsRW{};
  std::vector<std::string> permissionsX{};
  std::vector<std::string> permissionsRWX{};
};

struct Scope FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef ScopeT NativeTableType;
  typedef ScopeBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_IDENTIFIER = 4,
    VT_NAME = 6,
    VT_DESCRIPTION = 8,
    VT_PERMISSIONSR = 10,
    VT_PERMISSIONSRW = 12,
    VT_PERMISSIONSX = 14,
    VT_PERMISSIONSRWX = 16
  };
  /// Identifier of the Scope
  const ::flatbuffers::String *identifier() const {
    return GetPointer<const ::flatbuffers::String *>(VT_IDENTIFIER);
  }
  ::flatbuffers::String *mutable_identifier() {
    return GetPointer<::flatbuffers::String *>(VT_IDENTIFIER);
  }
  bool KeyCompareLessThan(const Scope * const o) const {
    return *identifier() < *o->identifier();
  }
  int KeyCompareWithValue(const char *_identifier) const {
    return strcmp(identifier()->c_str(), _identifier);
  }
  /// Human readable name of the Scope
  const ::flatbuffers::String *name() const {
    return GetPointer<const ::flatbuffers::String *>(VT_NAME);
  }
  ::flatbuffers::String *mutable_name() {
    return GetPointer<::flatbuffers::String *>(VT_NAME);
  }
  /// Description of the Scope
  const ::flatbuffers::String *description() const {
    return GetPointer<const ::flatbuffers::String *>(VT_DESCRIPTION);
  }
  ::flatbuffers::String *mutable_description() {
    return GetPointer<::flatbuffers::String *>(VT_DESCRIPTION);
  }
  /// List of permission string for read operations
  const ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *permissionsR() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *>(VT_PERMISSIONSR);
  }
  ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *mutable_permissionsR() {
    return GetPointer<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *>(VT_PERMISSIONSR);
  }
  /// List of permission string for read/write operations
  const ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *permissionsRW() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *>(VT_PERMISSIONSRW);
  }
  ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *mutable_permissionsRW() {
    return GetPointer<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *>(VT_PERMISSIONSRW);
  }
  /// List of permission string for execute operations
  const ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *permissionsX() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *>(VT_PERMISSIONSX);
  }
  ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *mutable_permissionsX() {
    return GetPointer<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *>(VT_PERMISSIONSX);
  }
  /// List of permission string for all operations
  const ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *permissionsRWX() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *>(VT_PERMISSIONSRWX);
  }
  ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *mutable_permissionsRWX() {
    return GetPointer<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *>(VT_PERMISSIONSRWX);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_IDENTIFIER) &&
           verifier.VerifyString(identifier()) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyOffset(verifier, VT_DESCRIPTION) &&
           verifier.VerifyString(description()) &&
           VerifyOffset(verifier, VT_PERMISSIONSR) &&
           verifier.VerifyVector(permissionsR()) &&
           verifier.VerifyVectorOfStrings(permissionsR()) &&
           VerifyOffset(verifier, VT_PERMISSIONSRW) &&
           verifier.VerifyVector(permissionsRW()) &&
           verifier.VerifyVectorOfStrings(permissionsRW()) &&
           VerifyOffset(verifier, VT_PERMISSIONSX) &&
           verifier.VerifyVector(permissionsX()) &&
           verifier.VerifyVectorOfStrings(permissionsX()) &&
           VerifyOffset(verifier, VT_PERMISSIONSRWX) &&
           verifier.VerifyVector(permissionsRWX()) &&
           verifier.VerifyVectorOfStrings(permissionsRWX()) &&
           verifier.EndTable();
  }
  ScopeT *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(ScopeT *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<Scope> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const ScopeT* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct ScopeBuilder {
  typedef Scope Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_identifier(::flatbuffers::Offset<::flatbuffers::String> identifier) {
    fbb_.AddOffset(Scope::VT_IDENTIFIER, identifier);
  }
  void add_name(::flatbuffers::Offset<::flatbuffers::String> name) {
    fbb_.AddOffset(Scope::VT_NAME, name);
  }
  void add_description(::flatbuffers::Offset<::flatbuffers::String> description) {
    fbb_.AddOffset(Scope::VT_DESCRIPTION, description);
  }
  void add_permissionsR(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>>> permissionsR) {
    fbb_.AddOffset(Scope::VT_PERMISSIONSR, permissionsR);
  }
  void add_permissionsRW(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>>> permissionsRW) {
    fbb_.AddOffset(Scope::VT_PERMISSIONSRW, permissionsRW);
  }
  void add_permissionsX(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>>> permissionsX) {
    fbb_.AddOffset(Scope::VT_PERMISSIONSX, permissionsX);
  }
  void add_permissionsRWX(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>>> permissionsRWX) {
    fbb_.AddOffset(Scope::VT_PERMISSIONSRWX, permissionsRWX);
  }
  explicit ScopeBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<Scope> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<Scope>(end);
    fbb_.Required(o, Scope::VT_IDENTIFIER);
    return o;
  }
};

inline ::flatbuffers::Offset<Scope> CreateScope(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::String> identifier = 0,
    ::flatbuffers::Offset<::flatbuffers::String> name = 0,
    ::flatbuffers::Offset<::flatbuffers::String> description = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>>> permissionsR = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>>> permissionsRW = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>>> permissionsX = 0,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>>> permissionsRWX = 0) {
  ScopeBuilder builder_(_fbb);
  builder_.add_permissionsRWX(permissionsRWX);
  builder_.add_permissionsX(permissionsX);
  builder_.add_permissionsRW(permissionsRW);
  builder_.add_permissionsR(permissionsR);
  builder_.add_description(description);
  builder_.add_name(name);
  builder_.add_identifier(identifier);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<Scope> CreateScopeDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const char *identifier = nullptr,
    const char *name = nullptr,
    const char *description = nullptr,
    const std::vector<::flatbuffers::Offset<::flatbuffers::String>> *permissionsR = nullptr,
    const std::vector<::flatbuffers::Offset<::flatbuffers::String>> *permissionsRW = nullptr,
    const std::vector<::flatbuffers::Offset<::flatbuffers::String>> *permissionsX = nullptr,
    const std::vector<::flatbuffers::Offset<::flatbuffers::String>> *permissionsRWX = nullptr) {
  auto identifier__ = identifier ? _fbb.CreateString(identifier) : 0;
  auto name__ = name ? _fbb.CreateString(name) : 0;
  auto description__ = description ? _fbb.CreateString(description) : 0;
  auto permissionsR__ = permissionsR ? _fbb.CreateVector<::flatbuffers::Offset<::flatbuffers::String>>(*permissionsR) : 0;
  auto permissionsRW__ = permissionsRW ? _fbb.CreateVector<::flatbuffers::Offset<::flatbuffers::String>>(*permissionsRW) : 0;
  auto permissionsX__ = permissionsX ? _fbb.CreateVector<::flatbuffers::Offset<::flatbuffers::String>>(*permissionsX) : 0;
  auto permissionsRWX__ = permissionsRWX ? _fbb.CreateVector<::flatbuffers::Offset<::flatbuffers::String>>(*permissionsRWX) : 0;
  return comm::datalayer::CreateScope(
      _fbb,
      identifier__,
      name__,
      description__,
      permissionsR__,
      permissionsRW__,
      permissionsX__,
      permissionsRWX__);
}

::flatbuffers::Offset<Scope> CreateScope(::flatbuffers::FlatBufferBuilder &_fbb, const ScopeT *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline ScopeT *Scope::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<ScopeT>(new ScopeT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void Scope::UnPackTo(ScopeT *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = identifier(); if (_e) _o->identifier = _e->str(); }
  { auto _e = name(); if (_e) _o->name = _e->str(); }
  { auto _e = description(); if (_e) _o->description = _e->str(); }
  { auto _e = permissionsR(); if (_e) { _o->permissionsR.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->permissionsR[_i] = _e->Get(_i)->str(); } } else { _o->permissionsR.resize(0); } }
  { auto _e = permissionsRW(); if (_e) { _o->permissionsRW.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->permissionsRW[_i] = _e->Get(_i)->str(); } } else { _o->permissionsRW.resize(0); } }
  { auto _e = permissionsX(); if (_e) { _o->permissionsX.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->permissionsX[_i] = _e->Get(_i)->str(); } } else { _o->permissionsX.resize(0); } }
  { auto _e = permissionsRWX(); if (_e) { _o->permissionsRWX.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->permissionsRWX[_i] = _e->Get(_i)->str(); } } else { _o->permissionsRWX.resize(0); } }
}

inline ::flatbuffers::Offset<Scope> Scope::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const ScopeT* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateScope(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<Scope> CreateScope(::flatbuffers::FlatBufferBuilder &_fbb, const ScopeT *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const ScopeT* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _identifier = _fbb.CreateString(_o->identifier);
  auto _name = _o->name.empty() ? 0 : _fbb.CreateString(_o->name);
  auto _description = _o->description.empty() ? 0 : _fbb.CreateString(_o->description);
  auto _permissionsR = _o->permissionsR.size() ? _fbb.CreateVectorOfStrings(_o->permissionsR) : 0;
  auto _permissionsRW = _o->permissionsRW.size() ? _fbb.CreateVectorOfStrings(_o->permissionsRW) : 0;
  auto _permissionsX = _o->permissionsX.size() ? _fbb.CreateVectorOfStrings(_o->permissionsX) : 0;
  auto _permissionsRWX = _o->permissionsRWX.size() ? _fbb.CreateVectorOfStrings(_o->permissionsRWX) : 0;
  return comm::datalayer::CreateScope(
      _fbb,
      _identifier,
      _name,
      _description,
      _permissionsR,
      _permissionsRW,
      _permissionsX,
      _permissionsRWX);
}

inline const comm::datalayer::Scope *GetScope(const void *buf) {
  return ::flatbuffers::GetRoot<comm::datalayer::Scope>(buf);
}

inline const comm::datalayer::Scope *GetSizePrefixedScope(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<comm::datalayer::Scope>(buf);
}

inline Scope *GetMutableScope(void *buf) {
  return ::flatbuffers::GetMutableRoot<Scope>(buf);
}

inline comm::datalayer::Scope *GetMutableSizePrefixedScope(void *buf) {
  return ::flatbuffers::GetMutableSizePrefixedRoot<comm::datalayer::Scope>(buf);
}

inline bool VerifyScopeBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<comm::datalayer::Scope>(nullptr);
}

inline bool VerifySizePrefixedScopeBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<comm::datalayer::Scope>(nullptr);
}

inline void FinishScopeBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<comm::datalayer::Scope> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedScopeBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<comm::datalayer::Scope> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<comm::datalayer::ScopeT> UnPackScope(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::ScopeT>(GetScope(buf)->UnPack(res));
}

inline std::unique_ptr<comm::datalayer::ScopeT> UnPackSizePrefixedScope(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::ScopeT>(GetSizePrefixedScope(buf)->UnPack(res));
}

}  // namespace datalayer
}  // namespace comm

#endif  // FLATBUFFERS_GENERATED_SCOPE_COMM_DATALAYER_H_
