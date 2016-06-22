//
//  IGScraper.h
//  IGScraperKit
//
//  Created by Francis Chong on 12/22/13.
//  Copyright (c) 2013 Francis Chong. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "IGScraperDelegate.h"

@class IGXMLNode;



extern NSString* const IGScraperErrorDomain;



/**
 A IGScraper can scrape a HTML page and return arbitary object.
 */
@protocol IGScraping

/**
 A delegate that notify success or error of scraping.
 */
@property (nonatomic, weak) id<IGScraperDelegate> delegate;

/**
 Scrape the HTML.
 @param html HTML string
 @param NSURL URL of the page to be parsed
 
 @return object returned by scraper.
 */
-(id) scrapeWithHTML:(NSString*)html URL:(NSURL*)URL;

@end

/**
 */
@interface IGScraper : NSObject <IGScraping>

@property (nonatomic, weak) id<IGScraperDelegate> delegate;

/**
 A block to scrape the HTML.
 */
@property (nonatomic, copy) IGScraperBlock scraperBlock;

/**
 Store error during scraping.
 */
@property (nonatomic, strong) NSError* error;

/**
 Initialize a scraper with block.
 */
-(instancetype) initWithBlock:(IGScraperBlock)scaperBlock;

/**
 Create a scraper with block.
 */
+(instancetype) scraperWithBlock:(IGScraperBlock)scaperBlock;


/**
 Scrape the HTML.
 @param html HTML string
 @param url URL of the page to be parsed
 
 @return object returned by calling IGScraperBlock.
 */
-(id) scrapeWithHTML:(NSString*)html URL:(NSURL*)URL;

@end
