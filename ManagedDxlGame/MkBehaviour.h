

#pragma once
namespace MkEngine
{
	enum MkBehaviourType
	{
		/// <summary> 通常のライフサイクル </summary>
		Normal,
		/// <summary> グラフィックスのライフサイクル（描画処理が追加） </summary>
		Graphics,
		/// <summary> 物理演算のライフサイクル（毎フレーム呼び出しに制限） </summary>
		Physics,
		/// <summary> 要素数 </summary>
		Length
	};

	class MkBehaviour
	{
	private:
		MkEngine::MkBehaviourType m_type;

	public:
		const MkEngine::MkBehaviourType& get_BehaviourType()
		{
			return m_type;
		}

		virtual void Initialize() {}

		virtual void FixedUpdate(float deltaTime) {}

		virtual void DrawGraphics() {}

		virtual void MemRelease() {}
	};
}
