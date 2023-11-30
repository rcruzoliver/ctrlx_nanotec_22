// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_CONFIGITEM_COMM_DATALAYER_REMOTE_H_
#define FLATBUFFERS_GENERATED_CONFIGITEM_COMM_DATALAYER_REMOTE_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 1 &&
              FLATBUFFERS_VERSION_REVISION == 4,
             "Non-compatible flatbuffers version included");

namespace comm {
namespace datalayer {
namespace remote {

struct ConfigItem;
struct ConfigItemBuilder;
struct ConfigItemT;

struct ConfigItemT : public ::flatbuffers::NativeTable {
  typedef ConfigItem TableType;
  std::string name{};
  std::string address{};
};

struct ConfigItem FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef ConfigItemT NativeTableType;
  typedef ConfigItemBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_NAME = 4,
    VT_ADDRESS = 6
  };
  /// name of the remote connection
  const ::flatbuffers::String *name() const {
    return GetPointer<const ::flatbuffers::String *>(VT_NAME);
  }
  ::flatbuffers::String *mutable_name() {
    return GetPointer<::flatbuffers::String *>(VT_NAME);
  }
  bool KeyCompareLessThan(const ConfigItem * const o) const {
    return *name() < *o->name();
  }
  int KeyCompareWithValue(const char *_name) const {
    return strcmp(name()->c_str(), _name);
  }
  /// remote data layer connection string
  const ::flatbuffers::String *address() const {
    return GetPointer<const ::flatbuffers::String *>(VT_ADDRESS);
  }
  ::flatbuffers::String *mutable_address() {
    return GetPointer<::flatbuffers::String *>(VT_ADDRESS);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_NAME) &&
           verifier.VerifyString(name()) &&
           VerifyOffsetRequired(verifier, VT_ADDRESS) &&
           verifier.VerifyString(address()) &&
           verifier.EndTable();
  }
  ConfigItemT *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(ConfigItemT *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<ConfigItem> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const ConfigItemT* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct ConfigItemBuilder {
  typedef ConfigItem Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_name(::flatbuffers::Offset<::flatbuffers::String> name) {
    fbb_.AddOffset(ConfigItem::VT_NAME, name);
  }
  void add_address(::flatbuffers::Offset<::flatbuffers::String> address) {
    fbb_.AddOffset(ConfigItem::VT_ADDRESS, address);
  }
  explicit ConfigItemBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<ConfigItem> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<ConfigItem>(end);
    fbb_.Required(o, ConfigItem::VT_NAME);
    fbb_.Required(o, ConfigItem::VT_ADDRESS);
    return o;
  }
};

inline ::flatbuffers::Offset<ConfigItem> CreateConfigItem(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    ::flatbuffers::Offset<::flatbuffers::String> name = 0,
    ::flatbuffers::Offset<::flatbuffers::String> address = 0) {
  ConfigItemBuilder builder_(_fbb);
  builder_.add_address(address);
  builder_.add_name(name);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<ConfigItem> CreateConfigItemDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    const char *address = nullptr) {
  auto name__ = name ? _fbb.CreateString(name) : 0;
  auto address__ = address ? _fbb.CreateString(address) : 0;
  return comm::datalayer::remote::CreateConfigItem(
      _fbb,
      name__,
      address__);
}

::flatbuffers::Offset<ConfigItem> CreateConfigItem(::flatbuffers::FlatBufferBuilder &_fbb, const ConfigItemT *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline ConfigItemT *ConfigItem::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<ConfigItemT>(new ConfigItemT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void ConfigItem::UnPackTo(ConfigItemT *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = name(); if (_e) _o->name = _e->str(); }
  { auto _e = address(); if (_e) _o->address = _e->str(); }
}

inline ::flatbuffers::Offset<ConfigItem> ConfigItem::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const ConfigItemT* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateConfigItem(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<ConfigItem> CreateConfigItem(::flatbuffers::FlatBufferBuilder &_fbb, const ConfigItemT *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const ConfigItemT* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _name = _fbb.CreateString(_o->name);
  auto _address = _fbb.CreateString(_o->address);
  return comm::datalayer::remote::CreateConfigItem(
      _fbb,
      _name,
      _address);
}

inline const comm::datalayer::remote::ConfigItem *GetConfigItem(const void *buf) {
  return ::flatbuffers::GetRoot<comm::datalayer::remote::ConfigItem>(buf);
}

inline const comm::datalayer::remote::ConfigItem *GetSizePrefixedConfigItem(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<comm::datalayer::remote::ConfigItem>(buf);
}

inline ConfigItem *GetMutableConfigItem(void *buf) {
  return ::flatbuffers::GetMutableRoot<ConfigItem>(buf);
}

inline comm::datalayer::remote::ConfigItem *GetMutableSizePrefixedConfigItem(void *buf) {
  return ::flatbuffers::GetMutableSizePrefixedRoot<comm::datalayer::remote::ConfigItem>(buf);
}

inline bool VerifyConfigItemBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<comm::datalayer::remote::ConfigItem>(nullptr);
}

inline bool VerifySizePrefixedConfigItemBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<comm::datalayer::remote::ConfigItem>(nullptr);
}

inline void FinishConfigItemBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<comm::datalayer::remote::ConfigItem> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedConfigItemBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<comm::datalayer::remote::ConfigItem> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<comm::datalayer::remote::ConfigItemT> UnPackConfigItem(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::remote::ConfigItemT>(GetConfigItem(buf)->UnPack(res));
}

inline std::unique_ptr<comm::datalayer::remote::ConfigItemT> UnPackSizePrefixedConfigItem(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::remote::ConfigItemT>(GetSizePrefixedConfigItem(buf)->UnPack(res));
}

}  // namespace remote
}  // namespace datalayer
}  // namespace comm

#endif  // FLATBUFFERS_GENERATED_CONFIGITEM_COMM_DATALAYER_REMOTE_H_
