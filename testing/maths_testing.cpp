#include <gtest/gtest.h>
#include <gtest/gtest-matchers.h>
#include "maths/vec3.h"
#include "maths/mat4.h"

TEST(Vector3, ExpectedConstruction) {
	Vec3 expectedVector(-1.4f, 0.0f, 975.0f);

	EXPECT_FLOAT_EQ(expectedVector.x, -1.4f);
	EXPECT_FLOAT_EQ(expectedVector.y, 0.0f);
	EXPECT_FLOAT_EQ(expectedVector.z, 975.0f);
}

TEST(Vector3, DefaultConstructor) {
	Vec3 defaultVector;

	EXPECT_FLOAT_EQ(defaultVector.x, 0.0f);
	EXPECT_FLOAT_EQ(defaultVector.y, 0.0f);
	EXPECT_FLOAT_EQ(defaultVector.z, 0.0f);
}

TEST(Vector3, SquareMagnitude) {
	Vec3 vector(2.5f, 5.0f, -1.0f);
	float squareMagnitude = magnitudeSquared(vector);
	EXPECT_FLOAT_EQ(squareMagnitude, 32.25f);
}

TEST(Vector3, DotProduct) {
	Vec3 lhs(2.5f, 3.0f, 4.0f);
	Vec3 rhs(1.5f, 0.0f, 1.0f);
	float result = dot(lhs, rhs);
	EXPECT_FLOAT_EQ(result, 7.75f);
}

TEST(Vector3, CrossProduct) {
	Vec3 lhs(2.5f, 1.0f, -2.2f);
	Vec3 rhs(0.5f, 0.0f, 3.0f);
	Vec3 result = cross(lhs, rhs);

	EXPECT_FLOAT_EQ(result.x, 3.0f);
	EXPECT_FLOAT_EQ(result.y, -8.6f);
	EXPECT_FLOAT_EQ(result.z, -0.5f);
}

TEST(Vector3, Addition) {
	Vec3 lhs(1.5f, 3.2f, 9.1f);
	Vec3 rhs(9.3f, -4.2f, 4.2f);
	Vec3 result = lhs + rhs;

	EXPECT_FLOAT_EQ(result.x, 10.8f);
	EXPECT_FLOAT_EQ(result.y, -1.0f);
	EXPECT_FLOAT_EQ(result.z, 13.3f);
}

TEST(Vector3, Subtraction) {
	Vec3 lhs(4.2f, 8.4f, 1.2f);
	Vec3 rhs(-9.3f, 4.2f, 4.2f);
	Vec3 result = lhs - rhs;

	EXPECT_FLOAT_EQ(result.x, 13.5f);
	EXPECT_FLOAT_EQ(result.y, 4.2f);
	EXPECT_FLOAT_EQ(result.z, -3.0f);
}

TEST(Vector3, Division) {
	Vec3 vector(6.0f, 9.0f, -3.15f);
	Vec3 result = vector / 3.0f;

	EXPECT_FLOAT_EQ(result.x, 2.0f);
	EXPECT_FLOAT_EQ(result.y, 3.0f);
	EXPECT_FLOAT_EQ(result.z, -1.05f);
}

TEST(Mat4, DefaultConstruction) {
	Mat4 identity;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) { EXPECT_FLOAT_EQ(identity.getRow(i)[j], 1.0f); }
			else { EXPECT_FLOAT_EQ(identity.getRow(i)[j], 0.0f); }
		}
	}
}