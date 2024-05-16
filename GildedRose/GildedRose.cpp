#include "GildedRose.h"

class Calc {
public:
	virtual void updateQuality(Item& item) = 0;
};

class AgedBrie : public Calc {
public:
	void updateQuality(Item& item) override {
		item.sellIn--;
		if (item.quality < 50)
		{
			item.quality++;
		}
		if (item.quality < 50 && item.sellIn < 0) {
			item.quality++;
		}
	}
};

class Backstage : public Calc {
public:
	void updateQuality(Item& item) override {
		item.sellIn--;
		if (item.quality < 50)
		{
			if (item.sellIn < 0) {
				item.quality = 0;
				return;
			}

			item.quality++;

			if (item.sellIn < 11)
			{
				item.quality++;
			}

			if (item.sellIn < 6)
			{
				item.quality++;
			}
			return;
		}

		if (item.quality >= 50)
		{
			if (item.sellIn < 0) {
				item.quality = 0;
			}
		}
	}
};

class Sulfuras : public Calc {
public:
	void updateQuality(Item& item) override {
	}
};

class NoName : public Calc {
public:
	void updateQuality(Item& item) override {
		item.sellIn--;
		if (item.quality > 0)
		{
			item.quality--;
		}

		if (item.quality > 0)
		{
			if (item.sellIn < 0) {
				item.quality--;
			}
		}
	}
};

class Factory {
private:
	Calc* mAlgorithm;
	Calc* mAgedBrie;
	Calc* mSulfuras;
	Calc* mBackstage;
	Calc* mNoName;
public:
	Factory() {
		mAgedBrie = new AgedBrie();
		mSulfuras = new Sulfuras();
		mBackstage = new Backstage();
		mNoName = new NoName();
	}

	void setCalcAlgorithm(string algorithm) {
		if (algorithm == "Aged Brie") {
			mAlgorithm = mAgedBrie;
		}
		else if (algorithm == "Sulfuras, Hand of Ragnaros") {
			mAlgorithm = mSulfuras;
		}
		else if (algorithm == "Backstage passes to a TAFKAL80ETC concert") {
			mAlgorithm = mBackstage;
		}
		else {
			mAlgorithm = mNoName;
		}
	}

	void updateQuality(Item& item) {
		mAlgorithm->updateQuality(item);
	}
};

GildedRose::GildedRose(vector<Item>& items) : items(items)
{}

void GildedRose::updateQuality()
{
	Factory f;
	for (Item& item : items)
	{
		f.setCalcAlgorithm(item.name);
		f.updateQuality(item);
	}
}