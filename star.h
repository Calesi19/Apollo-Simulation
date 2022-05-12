


// star.h
namespace Apollo11
{
	class star
	{
	public:
		void setPosition();

		int getX();

		int getY();

		int getPhase();

	private:
		point position;
		int phase;

		void incrementPhase();

	};
}