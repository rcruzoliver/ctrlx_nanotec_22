// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_SERVERSETTINGS_COMM_DATALAYER_H_
#define FLATBUFFERS_GENERATED_SERVERSETTINGS_COMM_DATALAYER_H_

#include "flatbuffers/flatbuffers.h"

// Ensure the included flatbuffers.h is the same version as when this file was
// generated, otherwise it may not be compatible.
static_assert(FLATBUFFERS_VERSION_MAJOR == 23 &&
              FLATBUFFERS_VERSION_MINOR == 1 &&
              FLATBUFFERS_VERSION_REVISION == 4,
             "Non-compatible flatbuffers version included");

namespace comm {
namespace datalayer {

struct ServerSettings;
struct ServerSettingsBuilder;
struct ServerSettingsT;

struct ServerSettingsT : public ::flatbuffers::NativeTable {
  typedef ServerSettings TableType;
  uint32_t serverIdlePingTimeout = 30000;
  uint32_t serverWaitResponseTimeout = 3000;
  uint32_t serverMaxMessageSize = 52428800;
  std::string debugAddress{};
  uint32_t serverMaxRtSize = 1048576;
  uint32_t serverEmulatedNvramSize = 122880;
  std::vector<std::string> experimentalFeatures{};
};

struct ServerSettings FLATBUFFERS_FINAL_CLASS : private ::flatbuffers::Table {
  typedef ServerSettingsT NativeTableType;
  typedef ServerSettingsBuilder Builder;
  enum FlatBuffersVTableOffset FLATBUFFERS_VTABLE_UNDERLYING_TYPE {
    VT_SERVERIDLEPINGTIMEOUT = 4,
    VT_SERVERWAITRESPONSETIMEOUT = 6,
    VT_SERVERMAXMESSAGESIZE = 8,
    VT_DEBUGADDRESS = 10,
    VT_SERVERMAXRTSIZE = 12,
    VT_SERVEREMULATEDNVRAMSIZE = 14,
    VT_EXPERIMENTALFEATURES = 16
  };
  /// after this time send a ping to not used provider is send to test if provider is still alive
  uint32_t serverIdlePingTimeout() const {
    return GetField<uint32_t>(VT_SERVERIDLEPINGTIMEOUT, 30000);
  }
  bool mutate_serverIdlePingTimeout(uint32_t _serverIdlePingTimeout = 30000) {
    return SetField<uint32_t>(VT_SERVERIDLEPINGTIMEOUT, _serverIdlePingTimeout, 30000);
  }
  /// after this time a response from provider is expected - if there is no answer a provider is assumed to be dead --> kick provider out of routing
  uint32_t serverWaitResponseTimeout() const {
    return GetField<uint32_t>(VT_SERVERWAITRESPONSETIMEOUT, 3000);
  }
  bool mutate_serverWaitResponseTimeout(uint32_t _serverWaitResponseTimeout = 3000) {
    return SetField<uint32_t>(VT_SERVERWAITRESPONSETIMEOUT, _serverWaitResponseTimeout, 3000);
  }
  /// maximum inbound message size
  uint32_t serverMaxMessageSize() const {
    return GetField<uint32_t>(VT_SERVERMAXMESSAGESIZE, 52428800);
  }
  bool mutate_serverMaxMessageSize(uint32_t _serverMaxMessageSize = 52428800) {
    return SetField<uint32_t>(VT_SERVERMAXMESSAGESIZE, _serverMaxMessageSize, 52428800);
  }
  /// Address to debug disconnect
  const ::flatbuffers::String *debugAddress() const {
    return GetPointer<const ::flatbuffers::String *>(VT_DEBUGADDRESS);
  }
  ::flatbuffers::String *mutable_debugAddress() {
    return GetPointer<::flatbuffers::String *>(VT_DEBUGADDRESS);
  }
  /// Maximum size of a RT area
  uint32_t serverMaxRtSize() const {
    return GetField<uint32_t>(VT_SERVERMAXRTSIZE, 1048576);
  }
  bool mutate_serverMaxRtSize(uint32_t _serverMaxRtSize = 1048576) {
    return SetField<uint32_t>(VT_SERVERMAXRTSIZE, _serverMaxRtSize, 1048576);
  }
  /// Emulated NVRam size - will be active after a restart of app.automationcore
  uint32_t serverEmulatedNvramSize() const {
    return GetField<uint32_t>(VT_SERVEREMULATEDNVRAMSIZE, 122880);
  }
  bool mutate_serverEmulatedNvramSize(uint32_t _serverEmulatedNvramSize = 122880) {
    return SetField<uint32_t>(VT_SERVEREMULATEDNVRAMSIZE, _serverEmulatedNvramSize, 122880);
  }
  /// Add the names of the experimental feature you want to enable here
  const ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *experimentalFeatures() const {
    return GetPointer<const ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *>(VT_EXPERIMENTALFEATURES);
  }
  ::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *mutable_experimentalFeatures() {
    return GetPointer<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>> *>(VT_EXPERIMENTALFEATURES);
  }
  bool Verify(::flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint32_t>(verifier, VT_SERVERIDLEPINGTIMEOUT, 4) &&
           VerifyField<uint32_t>(verifier, VT_SERVERWAITRESPONSETIMEOUT, 4) &&
           VerifyField<uint32_t>(verifier, VT_SERVERMAXMESSAGESIZE, 4) &&
           VerifyOffset(verifier, VT_DEBUGADDRESS) &&
           verifier.VerifyString(debugAddress()) &&
           VerifyField<uint32_t>(verifier, VT_SERVERMAXRTSIZE, 4) &&
           VerifyField<uint32_t>(verifier, VT_SERVEREMULATEDNVRAMSIZE, 4) &&
           VerifyOffset(verifier, VT_EXPERIMENTALFEATURES) &&
           verifier.VerifyVector(experimentalFeatures()) &&
           verifier.VerifyVectorOfStrings(experimentalFeatures()) &&
           verifier.EndTable();
  }
  ServerSettingsT *UnPack(const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(ServerSettingsT *_o, const ::flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static ::flatbuffers::Offset<ServerSettings> Pack(::flatbuffers::FlatBufferBuilder &_fbb, const ServerSettingsT* _o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct ServerSettingsBuilder {
  typedef ServerSettings Table;
  ::flatbuffers::FlatBufferBuilder &fbb_;
  ::flatbuffers::uoffset_t start_;
  void add_serverIdlePingTimeout(uint32_t serverIdlePingTimeout) {
    fbb_.AddElement<uint32_t>(ServerSettings::VT_SERVERIDLEPINGTIMEOUT, serverIdlePingTimeout, 30000);
  }
  void add_serverWaitResponseTimeout(uint32_t serverWaitResponseTimeout) {
    fbb_.AddElement<uint32_t>(ServerSettings::VT_SERVERWAITRESPONSETIMEOUT, serverWaitResponseTimeout, 3000);
  }
  void add_serverMaxMessageSize(uint32_t serverMaxMessageSize) {
    fbb_.AddElement<uint32_t>(ServerSettings::VT_SERVERMAXMESSAGESIZE, serverMaxMessageSize, 52428800);
  }
  void add_debugAddress(::flatbuffers::Offset<::flatbuffers::String> debugAddress) {
    fbb_.AddOffset(ServerSettings::VT_DEBUGADDRESS, debugAddress);
  }
  void add_serverMaxRtSize(uint32_t serverMaxRtSize) {
    fbb_.AddElement<uint32_t>(ServerSettings::VT_SERVERMAXRTSIZE, serverMaxRtSize, 1048576);
  }
  void add_serverEmulatedNvramSize(uint32_t serverEmulatedNvramSize) {
    fbb_.AddElement<uint32_t>(ServerSettings::VT_SERVEREMULATEDNVRAMSIZE, serverEmulatedNvramSize, 122880);
  }
  void add_experimentalFeatures(::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>>> experimentalFeatures) {
    fbb_.AddOffset(ServerSettings::VT_EXPERIMENTALFEATURES, experimentalFeatures);
  }
  explicit ServerSettingsBuilder(::flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ::flatbuffers::Offset<ServerSettings> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = ::flatbuffers::Offset<ServerSettings>(end);
    return o;
  }
};

inline ::flatbuffers::Offset<ServerSettings> CreateServerSettings(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t serverIdlePingTimeout = 30000,
    uint32_t serverWaitResponseTimeout = 3000,
    uint32_t serverMaxMessageSize = 52428800,
    ::flatbuffers::Offset<::flatbuffers::String> debugAddress = 0,
    uint32_t serverMaxRtSize = 1048576,
    uint32_t serverEmulatedNvramSize = 122880,
    ::flatbuffers::Offset<::flatbuffers::Vector<::flatbuffers::Offset<::flatbuffers::String>>> experimentalFeatures = 0) {
  ServerSettingsBuilder builder_(_fbb);
  builder_.add_experimentalFeatures(experimentalFeatures);
  builder_.add_serverEmulatedNvramSize(serverEmulatedNvramSize);
  builder_.add_serverMaxRtSize(serverMaxRtSize);
  builder_.add_debugAddress(debugAddress);
  builder_.add_serverMaxMessageSize(serverMaxMessageSize);
  builder_.add_serverWaitResponseTimeout(serverWaitResponseTimeout);
  builder_.add_serverIdlePingTimeout(serverIdlePingTimeout);
  return builder_.Finish();
}

inline ::flatbuffers::Offset<ServerSettings> CreateServerSettingsDirect(
    ::flatbuffers::FlatBufferBuilder &_fbb,
    uint32_t serverIdlePingTimeout = 30000,
    uint32_t serverWaitResponseTimeout = 3000,
    uint32_t serverMaxMessageSize = 52428800,
    const char *debugAddress = nullptr,
    uint32_t serverMaxRtSize = 1048576,
    uint32_t serverEmulatedNvramSize = 122880,
    const std::vector<::flatbuffers::Offset<::flatbuffers::String>> *experimentalFeatures = nullptr) {
  auto debugAddress__ = debugAddress ? _fbb.CreateString(debugAddress) : 0;
  auto experimentalFeatures__ = experimentalFeatures ? _fbb.CreateVector<::flatbuffers::Offset<::flatbuffers::String>>(*experimentalFeatures) : 0;
  return comm::datalayer::CreateServerSettings(
      _fbb,
      serverIdlePingTimeout,
      serverWaitResponseTimeout,
      serverMaxMessageSize,
      debugAddress__,
      serverMaxRtSize,
      serverEmulatedNvramSize,
      experimentalFeatures__);
}

::flatbuffers::Offset<ServerSettings> CreateServerSettings(::flatbuffers::FlatBufferBuilder &_fbb, const ServerSettingsT *_o, const ::flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline ServerSettingsT *ServerSettings::UnPack(const ::flatbuffers::resolver_function_t *_resolver) const {
  auto _o = std::unique_ptr<ServerSettingsT>(new ServerSettingsT());
  UnPackTo(_o.get(), _resolver);
  return _o.release();
}

inline void ServerSettings::UnPackTo(ServerSettingsT *_o, const ::flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = serverIdlePingTimeout(); _o->serverIdlePingTimeout = _e; }
  { auto _e = serverWaitResponseTimeout(); _o->serverWaitResponseTimeout = _e; }
  { auto _e = serverMaxMessageSize(); _o->serverMaxMessageSize = _e; }
  { auto _e = debugAddress(); if (_e) _o->debugAddress = _e->str(); }
  { auto _e = serverMaxRtSize(); _o->serverMaxRtSize = _e; }
  { auto _e = serverEmulatedNvramSize(); _o->serverEmulatedNvramSize = _e; }
  { auto _e = experimentalFeatures(); if (_e) { _o->experimentalFeatures.resize(_e->size()); for (::flatbuffers::uoffset_t _i = 0; _i < _e->size(); _i++) { _o->experimentalFeatures[_i] = _e->Get(_i)->str(); } } else { _o->experimentalFeatures.resize(0); } }
}

inline ::flatbuffers::Offset<ServerSettings> ServerSettings::Pack(::flatbuffers::FlatBufferBuilder &_fbb, const ServerSettingsT* _o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  return CreateServerSettings(_fbb, _o, _rehasher);
}

inline ::flatbuffers::Offset<ServerSettings> CreateServerSettings(::flatbuffers::FlatBufferBuilder &_fbb, const ServerSettingsT *_o, const ::flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { ::flatbuffers::FlatBufferBuilder *__fbb; const ServerSettingsT* __o; const ::flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _serverIdlePingTimeout = _o->serverIdlePingTimeout;
  auto _serverWaitResponseTimeout = _o->serverWaitResponseTimeout;
  auto _serverMaxMessageSize = _o->serverMaxMessageSize;
  auto _debugAddress = _o->debugAddress.empty() ? 0 : _fbb.CreateString(_o->debugAddress);
  auto _serverMaxRtSize = _o->serverMaxRtSize;
  auto _serverEmulatedNvramSize = _o->serverEmulatedNvramSize;
  auto _experimentalFeatures = _o->experimentalFeatures.size() ? _fbb.CreateVectorOfStrings(_o->experimentalFeatures) : 0;
  return comm::datalayer::CreateServerSettings(
      _fbb,
      _serverIdlePingTimeout,
      _serverWaitResponseTimeout,
      _serverMaxMessageSize,
      _debugAddress,
      _serverMaxRtSize,
      _serverEmulatedNvramSize,
      _experimentalFeatures);
}

inline const comm::datalayer::ServerSettings *GetServerSettings(const void *buf) {
  return ::flatbuffers::GetRoot<comm::datalayer::ServerSettings>(buf);
}

inline const comm::datalayer::ServerSettings *GetSizePrefixedServerSettings(const void *buf) {
  return ::flatbuffers::GetSizePrefixedRoot<comm::datalayer::ServerSettings>(buf);
}

inline ServerSettings *GetMutableServerSettings(void *buf) {
  return ::flatbuffers::GetMutableRoot<ServerSettings>(buf);
}

inline comm::datalayer::ServerSettings *GetMutableSizePrefixedServerSettings(void *buf) {
  return ::flatbuffers::GetMutableSizePrefixedRoot<comm::datalayer::ServerSettings>(buf);
}

inline bool VerifyServerSettingsBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<comm::datalayer::ServerSettings>(nullptr);
}

inline bool VerifySizePrefixedServerSettingsBuffer(
    ::flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<comm::datalayer::ServerSettings>(nullptr);
}

inline void FinishServerSettingsBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<comm::datalayer::ServerSettings> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedServerSettingsBuffer(
    ::flatbuffers::FlatBufferBuilder &fbb,
    ::flatbuffers::Offset<comm::datalayer::ServerSettings> root) {
  fbb.FinishSizePrefixed(root);
}

inline std::unique_ptr<comm::datalayer::ServerSettingsT> UnPackServerSettings(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::ServerSettingsT>(GetServerSettings(buf)->UnPack(res));
}

inline std::unique_ptr<comm::datalayer::ServerSettingsT> UnPackSizePrefixedServerSettings(
    const void *buf,
    const ::flatbuffers::resolver_function_t *res = nullptr) {
  return std::unique_ptr<comm::datalayer::ServerSettingsT>(GetSizePrefixedServerSettings(buf)->UnPack(res));
}

}  // namespace datalayer
}  // namespace comm

#endif  // FLATBUFFERS_GENERATED_SERVERSETTINGS_COMM_DATALAYER_H_
