#include <gtest/gtest.h>
#include <gtest/gtest-matchers.h>
#include "maths/vec3.h"
#include "maths/mat4.h"

TEST(Vector3, ExpectedConstruction) {
	Vec3 expectedVector(-1.4f, 0.0f, 975.0f);

	EXPECT_FLOAT_EQ(expectedVector.x(), -1.4f);
	EXPECT_FLOAT_EQ(expectedVector.y(), 0.0f);
	EXPECT_FLOAT_EQ(expectedVector.z(), 975.0f);
}

TEST(Vector3, DefaultConstructor) {
	Vec3 defaultVector;

	EXPECT_FLOAT_EQ(defaultVector.x(), 0.0f);
	EXPECT_FLOAT_EQ(defaultVector.y(), 0.0f);
	EXPECT_FLOAT_EQ(defaultVector.z(), 0.0f);
}

TEST(Vector3, Addition) {
	Vec3 lhs(1.5f, 3.2f, 9.1f);
	Vec3 rhs(9.3f, -4.2f, 4.2f);
	Vec3 result = lhs + rhs;

	EXPECT_FLOAT_EQ(result.x(), 10.8f);
	EXPECT_FLOAT_EQ(result.y(), -1.0f);
	EXPECT_FLOAT_EQ(result.z(), 13.3f);
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