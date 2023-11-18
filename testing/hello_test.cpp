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

TEST(Mat4, DefaultConstruction) {
	Mat4 identity;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (i == j) { EXPECT_FLOAT_EQ(identity.getRow(i)[j], 1.0f); }
			else { EXPECT_FLOAT_EQ(identity.getRow(i)[j], 0.0f); }
		}
	}
}