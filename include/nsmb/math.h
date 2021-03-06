#ifndef NSMB_MATH_H_
#define NSMB_MATH_H_

#include "nitro_if.h"


namespace Math {

	//u32:02043380
	//u16:02043398
	//s16:020433b0
	//u8:020433c8
	//s8:020433e0
	u32 timerTick(u32* timer);
	u16 timerTick(u16* timer);
	s16 timerTick(s16* timer);
	u8  timerTick(u8* timer);
	s8  timerTick(s8* timer);

	//020433f8
	//02043464
	//020434d8
	//s16:0204354c
	//020435a8

	//lerp:02043604
	void lerp(s16& start, s16 end, s16 ratio, s16 maxStep);

	//02043674
	s16 lerp(s16& start, s16 end, s16 ratio, s16 maxStep, s16 minStep);

	//02043750
	bool inRange(s32 x, s32 a, s32 b);

	//02043790
	s16 distance(s16 a, s16 b);

	//020437a4
	//020437f4

	//020848e4
	extern fx16 atan2Table[1025];

	//02043b6c
	fx16 atan2(fx32 y, fx32 x);

	//0208b668
	extern u32 frameCounter;

	//0208b66c
	extern u32 unusedCounter;

	//02043d10
	void resetFrameCounters();

	//02043d30
	fx16 angle(const Vec3& a, const Vec3& b);//X and Z

	//2D:02043d5c
	bool lerp(Vec2& start, const Vec2& end, fx32 step);

	//3D:02043e30
	bool lerp(Vec3& start, const Vec3& end, fx32 step);

	//02043f10
	void lerp(Vec2& start, const Vec2& end, fx32 scale, fx32 maxStep);

	//02043fe0
	void lerp(Vec2& start, const Vec2& end, fx32 scale, fx32 maxStep, fx32 minStep);

	//02044120
	void lerp(Vec3& start, const Vec3& end, fx32 scale, fx32 maxStep, fx32 minStep);

	//02044280 (sub?)
	//void subtract();

	//020442b0
	u32 nextRandom(u32& value);

	//020442dc
	u32 generateSeed();


	constexpr inline int fromRadians(fx32 r) {
		return (r * FX32_CONST(0x10000)) / FX64C_TWOPI;
	}
	constexpr inline int fromDegrees(int d) {
		return (d * 0x10000) / 360;
	}

	template<typename T>
	constexpr inline void swap(T& a, T& b) {
		T tmp = a;
		a = b;
		b = tmp;
	}


#define ToFx16(x)		FX16_CONST(x)
#define ToFx32(x)		FX32_CONST(x)
#define ToFx64(x)		FX64_CONST(x)
#define ToFx64c(x)		FX64C_CONST(x)

#define IntToFx32(x)	((x) << 12)

#define Fx32ToF32(x)	((x) / (float)FX32_ONE)
#define Fx32ToInt(x)	FX_Whole(x)

#define ToAngle(x)		(((x) * 0x10000) / 360)


	static inline fx16 sin(int idx) {
		return FX_SinIdx(u32(idx) & 0xFFFF);
	}
	static inline fx16 cos(int idx) {
		return FX_CosIdx(u32(idx) & 0xFFFF);
	}
	static inline fx32 mul(fx32 a, fx32 b) {
		return FX_Mul(a, b);
	}
	static inline fx32 div(fx32 n, fx32 d) {
		return FX_Div(n, d);
	}
	static inline fx32 inv(fx32 d) {
		return FX_Inv(d);
	}
	static inline fx32 sqrt(fx32 p) {
		return FX_Sqrt(p);
	}


	//02044308 wtf

	namespace Random {

		// 0200e6f4
		GEN_SFUNC( u32 stageRandom ) // used in stage related operations (actors, spawns, tile randomization)

	}


}




#endif // !NSMB_MATH_H_
