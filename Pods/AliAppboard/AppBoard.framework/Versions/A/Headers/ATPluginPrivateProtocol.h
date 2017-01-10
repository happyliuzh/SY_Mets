//
//  ATPluginPrivateProtocol.h
//  AT
//
//  Created by ZhuBicheng on 16/2/23.
//  Copyright © 2016年 当扈. All rights reserved.
//

#ifndef ATPluginPrivateProtocol_h
#define ATPluginPrivateProtocol_h

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

@protocol ATPluginPrivateProtocol <NSObject>

@optional

- (void)containerTapInView:(UIView *)view;


@end


@protocol ATPluginDelegate

- (void)pluginDidLoadInContainerViewController:(UIViewController *)containerViewController withArgs:(NSArray *)args;

- (CGRect)reactAreaInBaseWindow;

@optional
- (CGRect)reactAreaInPresenterWindow;

@optional

- (void)pluginDidUnloadInContainViewController:(UIViewController *)containerViewController;

- (void)containerViewControllerTapInView:(UIView *)view;

- (CGRect)wantIgnoreArea;

@end

#endif /* ATPluginPrivateProtocol_h */
