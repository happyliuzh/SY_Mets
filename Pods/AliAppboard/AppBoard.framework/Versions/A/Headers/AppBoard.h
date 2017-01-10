//
//  ATManager.h
//  AT
//
//  Created by ZhuBicheng on 15/7/14.
//  Copyright © 2015年 alibaba. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AppBoard : NSObject

@property (nonatomic,assign) BOOL wantFullTouchable;

@property (nonatomic,strong) NSString *watermark;

@property (nonatomic, strong, readonly) NSMutableArray *customizePluginArray;

@property (nonatomic, strong, readonly) NSMutableDictionary *customizeSubPluginDic;

@property (nonatomic, strong, readonly) NSArray *removedPluginIdArray;

@property (nonatomic, assign, readonly) BOOL hasCrashSDK;

@property (nonatomic, assign, readonly) NSInteger checkUpdateResult;

@property (nonatomic, strong, readonly) NSString *checkUpdateResultMsg;

@property (nonatomic, assign, readonly) BOOL isNeedRecheck;

@property (nonatomic, assign, readonly) BOOL isAppKeyLegal;

@property (nonatomic, strong, readonly) NSString *appKey;

@property (nonatomic, strong, readonly) NSString *appSecret;

@property (nonatomic, strong, readonly) NSString *channel;


+ (AppBoard *)sharedInstance;

- (void)authWithAppKey:(NSString *)appKey
          andAppSecret:(NSString *)appSecurity
            andChannel:(NSString *)channel;

/**
 *  添加一级自定义插件
 *
 *  @param pluginId                插件id
 *  @param pluginName              插件name
 *  @param pluginIconName          插件图标
 *  @param pluginEntry             插件入口类
 *  @param pluginArgs              插件参数
 */
- (void)addPluginWithId:(NSString *)pluginId
                andName:(NSString *)pluginName
            andIconName:(NSString *)pluginIconName
               andEntry:(NSString *)pluginEntry
                andArgs:(NSArray *)pluginArgs;

/**
 *  添加二级自定义插件
 *
 *  @param parentPluginId          一级插件id
 *  @param subPluginId             二级插件id
 *  @param pluginName              二级插件name
 *  @param pluginIconName          二级插件图标
 *  @param pluginEntry             二级插件入口类
 *  @param pluginArgs              二级插件参数
 */
- (void)addSubPluginWithParentId:(NSString *)parentPluginId
                        andSubId:(NSString *)subPluginId
                         andName:(NSString *)pluginName
                     andIconName:(NSString *)pluginIconName
                        andEntry:(NSString *)pluginEntry
                         andArgs:(NSArray *)pluginArgs;

/**
 *  移除预置的插件
 *
 *  @param pluginIdArray 待移除的插件id
 */
- (void)removePluginsByPluginIdArray:(NSArray *)pluginIdArray;

/**
 *  根据plist配置文件，添加自定义插件
 *
 *  @param plistName plist名称
 */
- (void)addPluginByConfigPlistName:(NSString *)plistName;

/**
 *  重载所有插件
 */
- (void)reload;

@end



