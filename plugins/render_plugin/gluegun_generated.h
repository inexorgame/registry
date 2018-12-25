// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_GLUEGUN_INEXORGAME_PLUGIN_H_
#define FLATBUFFERS_GENERATED_GLUEGUN_INEXORGAME_PLUGIN_H_

#include "flatbuffers/flatbuffers.h"

namespace inexorgame {
namespace plugin {

struct PluginId;

struct PluginMessage;

/// Describes the possible signals in gluegun
enum LifeCycleSignals {
  /// a Plugin asks for registration to the registry/a plugin
  LifeCycleSignals_RegisterMe = 0  /// instructs a plugin to register itself to another plugin
,
  LifeCycleSignals_PairWithPlugin = 1  /// registry asks a plugin to shut down
,
  LifeCycleSignals_Shutdown = 127,
  LifeCycleSignals_MIN = LifeCycleSignals_RegisterMe,
  LifeCycleSignals_MAX = LifeCycleSignals_Shutdown
};

inline const LifeCycleSignals (&EnumValuesLifeCycleSignals())[3] {
  static const LifeCycleSignals values[] = {
    LifeCycleSignals_RegisterMe,
    LifeCycleSignals_PairWithPlugin,
    LifeCycleSignals_Shutdown
  };
  return values;
}

inline const char *EnumNameLifeCycleSignals(LifeCycleSignals e) {
  switch (e) {
    case LifeCycleSignals_RegisterMe: return "RegisterMe";
    case LifeCycleSignals_PairWithPlugin: return "PairWithPlugin";
    case LifeCycleSignals_Shutdown: return "Shutdown";
    default: return "";
  }
}

/// information about a component / plugin to identify it (e.g. for registration)
struct PluginId FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_ADDRESS = 4
  };
  /// The socket address of this plugin
  const flatbuffers::String *address() const {
    return GetPointer<const flatbuffers::String *>(VT_ADDRESS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_ADDRESS) &&
           verifier.VerifyString(address()) &&
           verifier.EndTable();
  }
};

struct PluginIdBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_address(flatbuffers::Offset<flatbuffers::String> address) {
    fbb_.AddOffset(PluginId::VT_ADDRESS, address);
  }
  explicit PluginIdBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  PluginIdBuilder &operator=(const PluginIdBuilder &);
  flatbuffers::Offset<PluginId> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<PluginId>(end);
    return o;
  }
};

inline flatbuffers::Offset<PluginId> CreatePluginId(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> address = 0) {
  PluginIdBuilder builder_(_fbb);
  builder_.add_address(address);
  return builder_.Finish();
}

inline flatbuffers::Offset<PluginId> CreatePluginIdDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *address = nullptr) {
  return inexorgame::plugin::CreatePluginId(
      _fbb,
      address ? _fbb.CreateString(address) : 0);
}

/// Describes the gluegun root type which can contain components or log messages
struct PluginMessage FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_SIGNAL_TYPE = 4,
    VT_PLUGIN_ID = 6
  };
  LifeCycleSignals signal_type() const {
    return static_cast<LifeCycleSignals>(GetField<int8_t>(VT_SIGNAL_TYPE, 0));
  }
  const PluginId *plugin_id() const {
    return GetPointer<const PluginId *>(VT_PLUGIN_ID);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<int8_t>(verifier, VT_SIGNAL_TYPE) &&
           VerifyOffset(verifier, VT_PLUGIN_ID) &&
           verifier.VerifyTable(plugin_id()) &&
           verifier.EndTable();
  }
};

struct PluginMessageBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_signal_type(LifeCycleSignals signal_type) {
    fbb_.AddElement<int8_t>(PluginMessage::VT_SIGNAL_TYPE, static_cast<int8_t>(signal_type), 0);
  }
  void add_plugin_id(flatbuffers::Offset<PluginId> plugin_id) {
    fbb_.AddOffset(PluginMessage::VT_PLUGIN_ID, plugin_id);
  }
  explicit PluginMessageBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  PluginMessageBuilder &operator=(const PluginMessageBuilder &);
  flatbuffers::Offset<PluginMessage> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<PluginMessage>(end);
    return o;
  }
};

inline flatbuffers::Offset<PluginMessage> CreatePluginMessage(
    flatbuffers::FlatBufferBuilder &_fbb,
    LifeCycleSignals signal_type = LifeCycleSignals_RegisterMe,
    flatbuffers::Offset<PluginId> plugin_id = 0) {
  PluginMessageBuilder builder_(_fbb);
  builder_.add_plugin_id(plugin_id);
  builder_.add_signal_type(signal_type);
  return builder_.Finish();
}

inline const inexorgame::plugin::PluginMessage *GetPluginMessage(const void *buf) {
  return flatbuffers::GetRoot<inexorgame::plugin::PluginMessage>(buf);
}

inline const inexorgame::plugin::PluginMessage *GetSizePrefixedPluginMessage(const void *buf) {
  return flatbuffers::GetSizePrefixedRoot<inexorgame::plugin::PluginMessage>(buf);
}

inline bool VerifyPluginMessageBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifyBuffer<inexorgame::plugin::PluginMessage>(nullptr);
}

inline bool VerifySizePrefixedPluginMessageBuffer(
    flatbuffers::Verifier &verifier) {
  return verifier.VerifySizePrefixedBuffer<inexorgame::plugin::PluginMessage>(nullptr);
}

inline void FinishPluginMessageBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<inexorgame::plugin::PluginMessage> root) {
  fbb.Finish(root);
}

inline void FinishSizePrefixedPluginMessageBuffer(
    flatbuffers::FlatBufferBuilder &fbb,
    flatbuffers::Offset<inexorgame::plugin::PluginMessage> root) {
  fbb.FinishSizePrefixed(root);
}

}  // namespace plugin
}  // namespace inexorgame

#endif  // FLATBUFFERS_GENERATED_GLUEGUN_INEXORGAME_PLUGIN_H_
