#ifndef COLOR_SPACE_H
#define COLOR_SPACE_H

#include <typeinfo>
#include "Conversion.h"
#include "glm/glm.hpp"

namespace ColorSpace {
	struct IColorSpace {
		IColorSpace() {}
		virtual ~IColorSpace() {}

		virtual void Initialize(Rgb *color) = 0;
		virtual void ToRgb(Rgb *color) = 0;
		virtual void Copy(IColorSpace *color) = 0;
		template <typename TColorSpace>
		void To(TColorSpace *color) {
			Rgb rgb;

			if (typeid(*this) == typeid(*color)) {
				this->Copy(color);
			}
			else {
				this->ToRgb(&rgb);
				IConverter<TColorSpace>::ToColorSpace(&rgb, color);
			}
		}

		virtual glm::vec3 getComponent() = 0;

	};


	struct Rgb : public IColorSpace {
		double r, g, b;

		Rgb();
		Rgb(double r, double g, double b);

		void Initialize(Rgb *color);
		void ToRgb(Rgb *color);
		void Copy(IColorSpace *color);
		glm::vec3 getComponent() { return glm::vec3(r, g, b); }
	};

	struct Xyz : public IColorSpace {
		double x, y, z;

		Xyz();
		Xyz(double x, double y, double z);

		void Initialize(Rgb *color);
		void ToRgb(Rgb *color);
		void Copy(IColorSpace *color);
		glm::vec3 getComponent() { return glm::vec3(x, y, z); }
	};

	struct Hsl : public IColorSpace {
		double h, s, l;

		Hsl();
		Hsl(double h, double s, double l);

		void Initialize(Rgb *color);
		void ToRgb(Rgb *color);
		void Copy(IColorSpace *color);
		glm::vec3 getComponent() { return glm::vec3(h, s, l); }
	};

	struct Lab : public IColorSpace {
		double l, a, b;

		Lab();
		Lab(double l, double a, double b);

		void Initialize(Rgb *color);
		void ToRgb(Rgb *color);
		void Copy(IColorSpace *color);
		glm::vec3 getComponent() { return glm::vec3(l, a, b); }
	};

	struct Lch : public IColorSpace {
		double l, c, h;

		Lch();
		Lch(double l, double c, double h);

		void Initialize(Rgb *color);
		void ToRgb(Rgb *color);
		void Copy(IColorSpace *color);
		glm::vec3 getComponent() { return glm::vec3(l, c, h); }
	};

	struct Luv : public IColorSpace {
		double l, u, v;

		Luv();
		Luv(double l, double u, double v);

		void Initialize(Rgb *color);
		void ToRgb(Rgb *color);
		void Copy(IColorSpace *color);
		glm::vec3 getComponent() { return glm::vec3(l, u, v); }
	};

	struct Yxy : public IColorSpace {
		double y1, x, y2;

		Yxy();
		Yxy(double y1, double x, double y2);

		void Initialize(Rgb *color);
		void ToRgb(Rgb *color);
		void Copy(IColorSpace *color);
		glm::vec3 getComponent() { return glm::vec3(y1, x, y2); }
	};

	struct Cmy : public IColorSpace {
		double c, m, y;

		Cmy();
		Cmy(double c, double m, double y);

		void Initialize(Rgb *color);
		void ToRgb(Rgb *color);
		void Copy(IColorSpace *color);
		glm::vec3 getComponent() { return glm::vec3(c, m, y); }
	};

	struct Cmyk : public IColorSpace {
		double c, m, y, k;

		Cmyk();
		Cmyk(double c, double m, double y, double k);

		void Initialize(Rgb *color);
		void ToRgb(Rgb *color);
		void Copy(IColorSpace *color);
		glm::vec3 getComponent() { return glm::vec3(c, m, y); }
	};

	struct Hsv : public IColorSpace {
		double h, s, v;

		Hsv();
		Hsv(double h, double s, double v);

		void Initialize(Rgb *color);
		void ToRgb(Rgb *color);
		void Copy(IColorSpace *color);
		glm::vec3 getComponent() { return glm::vec3(h, s, v); }
	};

	struct Hsb : public IColorSpace {
		double h, s, b;

		Hsb();
		Hsb(double h, double s, double b);

		void Initialize(Rgb *color);
		void ToRgb(Rgb *color);
		void Copy(IColorSpace *color);
		glm::vec3 getComponent() { return glm::vec3(h, s, b); }
	};

	struct HunterLab : public IColorSpace {
		double l, a, b;

		HunterLab();
		HunterLab(double l, double a, double b);

		void Initialize(Rgb *color);
		void ToRgb(Rgb *color);
		void Copy(IColorSpace *color);
		glm::vec3 getComponent() { return glm::vec3(l, a, b); }
	};
}

#endif // COLOR_SPACE_H

