#ifndef HINAPE_COMMON_H
#define HINAPE_COMMON_H

class NoCopy
{
public:
	NoCopy() = default;
	~NoCopy() = default;
	NoCopy(const NoCopy &) = delete;
	NoCopy(NoCopy &&) = default;
	auto operator=(const NoCopy &) -> NoCopy & = delete;
	auto operator=(NoCopy &&) -> NoCopy & = default;
};

class NoMove
{
public:
	NoMove() = default;
	~NoMove() = default;
	NoMove(const NoMove &) = default;
	NoMove(NoMove &&) = delete;
	auto operator=(const NoMove &) -> NoMove & = default;
	auto operator=(NoMove &&) -> NoMove & = delete;
};

class NoCopyAndMove
{
public:
	NoCopyAndMove() = default;
	~NoCopyAndMove() = default;
	NoCopyAndMove(const NoCopyAndMove &) = delete;
	NoCopyAndMove(NoCopyAndMove &&) = delete;
	auto operator=(const NoCopyAndMove &) -> NoCopyAndMove & = delete;
	auto operator=(NoCopyAndMove &&) -> NoCopyAndMove & = delete;
};

#endif //HINAPE_COMMON_H
