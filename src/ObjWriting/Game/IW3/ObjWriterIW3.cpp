#include "ObjWriterIW3.h"
#include "ReplayMapDumpers.h"

#include "Game/IW3/Font/FontDumperIW3.h"
#include "Game/IW3/Image/ImageDumperIW3.h"
#include "Game/IW3/Maps/MapEntsDumperIW3.h"
#include "Game/IW3/Material/MaterialJsonDumperIW3.h"
#include "Game/IW3/Techset/TechsetDumperIW3.h"
#include "Game/IW3/XAnim/XAnimDumperIW3.h"
#include "Game/IW3/XModel/XModelDumperIW3.h"
#include "LightDef/LightDefDumperIW3.h"
#include "Localize/LocalizeDumperIW3.h"
#include "Menu/MenuDumperIW3.h"
#include "Menu/MenuListDumperIW3.h"
#include "PhysPreset/PhysPresetInfoStringDumperIW3.h"
#include "RawFile/RawFileDumperIW3.h"
#include "Sound/LoadedSoundDumperIW3.h"
#include "Sound/SndCurveDumperIW3.h"
#include "StringTable/StringTableDumperIW3.h"
#include "Weapon/WeaponDumperIW3.h"

using namespace IW3;

void ObjWriter::RegisterAssetDumpers(AssetDumpingContext& context)
{
    RegisterAssetDumper(std::make_unique<phys_preset::InfoStringDumperIW3>());
    // Raw IW3 streams for the Replay converter (replaces the modtools-format dump).
    RegisterAssetDumper(std::make_unique<replay_export::XAnim>());
    RegisterAssetDumper(std::make_unique<xmodel::DumperIW3>());
    RegisterAssetDumper(std::make_unique<replay_export::Model>());
    RegisterAssetDumper(std::make_unique<material::JsonDumperIW3>());
    RegisterAssetDumper(std::make_unique<techset::DumperIW3>(
#ifdef TECHSET_DEBUG
        true
#else
        false
#endif
        ));
    RegisterAssetDumper(std::make_unique<image::DumperIW3>());
    RegisterAssetDumper(std::make_unique<replay_export::Sound>());
    RegisterAssetDumper(std::make_unique<sound_curve::DumperIW3>());
    RegisterAssetDumper(std::make_unique<sound::LoadedSoundDumperIW3>());
    RegisterAssetDumper(std::make_unique<replay_export::Collision<IW3::AssetClipMap>>()); RegisterAssetDumper(std::make_unique<replay_export::Collision<IW3::AssetClipMapPvs>>());
    RegisterAssetDumper(std::make_unique<replay_export::ComWorld>());
    // REGISTER_DUMPER(AssetDumperGameWorldSp)
    // REGISTER_DUMPER(AssetDumperGameWorldMp)
    RegisterAssetDumper(std::make_unique<map_ents::DumperIW3>());
    RegisterAssetDumper(std::make_unique<replay_export::World>());
    RegisterAssetDumper(std::make_unique<light_def::DumperIW3>());
    RegisterAssetDumper(std::make_unique<font::JsonDumperIW3>());
    RegisterAssetDumper(std::make_unique<menu::MenuListDumperIW3>());
    RegisterAssetDumper(std::make_unique<menu::MenuDumperIW3>());
    RegisterAssetDumper(std::make_unique<localize::DumperIW3>());
    RegisterAssetDumper(std::make_unique<weapon::DumperIW3>());
    // REGISTER_DUMPER(AssetDumperSndDriverGlobals)
    RegisterAssetDumper(std::make_unique<replay_export::Fx>());
    RegisterAssetDumper(std::make_unique<replay_export::ImpactFx>());
    RegisterAssetDumper(std::make_unique<raw_file::DumperIW3>());
    RegisterAssetDumper(std::make_unique<string_table::DumperIW3>());
}
