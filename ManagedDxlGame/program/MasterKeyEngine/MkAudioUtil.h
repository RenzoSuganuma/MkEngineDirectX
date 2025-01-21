#pragma once

#include "list"
#include "string"
#include "DxLib.h"
#include "unordered_map"

namespace MkEngine
{
	class MkAudio final
	{
	public:

		enum class AudioPlayMode
		{
			/// <summary> Ä¶‚µI‚í‚é‚Ü‚Åˆ—‚ğ~‚ß‚é </summary>
			Normal,
			/// <summary> ˆ—‚ğ~‚ß‚¸‚ÉÄ¶ </summary>
			BackGround,
			/// <summary> ƒ‹[ƒvÄ¶ </summary>
			Loop,
		};

		static std::unordered_map< std::string, int > m_soundHandlers;

		static const void LoadSoundToMemory(const std::string filePath, const std::string soundKey)
		{
			int num = LoadSoundMem(filePath.c_str());
			m_soundHandlers.insert(std::make_pair(soundKey, num));
		}

		static void PlaySoundFromMemory(const std::string soundKey, const AudioPlayMode audioPlayMode = AudioPlayMode::BackGround)
		{
			int mode;
			switch (audioPlayMode)
			{
			case AudioPlayMode::Normal:
				mode = DX_PLAYTYPE_NORMAL;
				break;
			case AudioPlayMode::BackGround:
				mode = DX_PLAYTYPE_BACK;
				break;
			default:	// Loop
				mode = DX_PLAYTYPE_LOOP;
				break;
			}

			if (m_soundHandlers.contains(soundKey)) {
				auto soundHandler = m_soundHandlers[soundKey];
				PlaySoundMem(soundHandler, mode);
			}
		}
	};
}
