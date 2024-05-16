#include "pch.h"
#include "../GildedRose/GildedRose.cpp"


TEST(TestCaseName, TestName1) {
    vector<Item> items;

    items.push_back(Item("+5 Dexterity Vest", 10, 20));
    items.push_back(Item("Aged Brie", 2, 0));
    items.push_back(Item("Elixir of the Mongoose", 5, 7));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", 0, 80));
    items.push_back(Item("Sulfuras, Hand of Ragnaros", -1, 80));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 15, 20));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 10, 49));
    items.push_back(Item("Backstage passes to a TAFKAL80ETC concert", 5, 49));
    items.push_back(Item("Conjured Mana Cake", 3, 6));

    GildedRose app(items);

    for (int day = 0; day < 30; day++)
    {
        app.updateQuality();
    }
    /*
    + 5 Dexterity Vest, -20, 0
        Aged Brie, -28, 50
        Elixir of the Mongoose, -25, 0
        Sulfuras, Hand of Ragnaros, 0, 80
        Sulfuras, Hand of Ragnaros, -1, 80
        Backstage passes to a TAFKAL80ETC concert, -15, 0
        Backstage passes to a TAFKAL80ETC concert, -20, 0
        Backstage passes to a TAFKAL80ETC concert, -25, 0
        Conjured Mana Cake, -27, 0
        */

    EXPECT_EQ("+5 Dexterity Vest", app.items[0].name);
    EXPECT_EQ(-20, app.items[0].sellIn);
    EXPECT_EQ(0, app.items[0].quality);

    EXPECT_EQ("Aged Brie", app.items[1].name);
    EXPECT_EQ(-28, app.items[1].sellIn);
    EXPECT_EQ(50, app.items[1].quality);

    EXPECT_EQ("Elixir of the Mongoose", app.items[2].name);
    EXPECT_EQ(-25, app.items[2].sellIn);
    EXPECT_EQ(0, app.items[2].quality);

    EXPECT_EQ("Sulfuras, Hand of Ragnaros", app.items[3].name);
    EXPECT_EQ(0, app.items[3].sellIn);
    EXPECT_EQ(80, app.items[3].quality);

    EXPECT_EQ("Sulfuras, Hand of Ragnaros", app.items[4].name);
    EXPECT_EQ(-1, app.items[4].sellIn);
    EXPECT_EQ(80, app.items[4].quality);

    EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", app.items[5].name);
    EXPECT_EQ(-15, app.items[5].sellIn);
    EXPECT_EQ(0, app.items[5].quality);

    EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", app.items[6].name);
    EXPECT_EQ(-20, app.items[6].sellIn);
    EXPECT_EQ(0, app.items[6].quality);

    EXPECT_EQ("Backstage passes to a TAFKAL80ETC concert", app.items[7].name);
    EXPECT_EQ(-25, app.items[7].sellIn);
    EXPECT_EQ(0, app.items[7].quality);

    EXPECT_EQ("Conjured Mana Cake", app.items[8].name);
    EXPECT_EQ(-27, app.items[8].sellIn);
    EXPECT_EQ(0, app.items[8].quality);
}

