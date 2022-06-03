#
#  Be sure to run `pod spec lint FPhiSelphIDWidgetiOSLight.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|
  s.name         = "FPhiPhingersCoreiOS"
  s.version      = "2.0.0"
  s.summary      = "Phingers widget for Fingerprint detection and recognition"
  s.description  = <<-DESC
                  Phingers widget for Fingerprint detection and recognition.
                  DESC
  s.homepage     = "http://www.facephi.com"
  s.license      = {
                    :type => "Commercial", 
                    :text => <<-LICENSE
                    © Facephi 2022. All rights reserved.
                    LICENSE
                  }
  s.authors      = { "FacePhi" => "support@facephi.com" }
  
  s.platform     = :ios, "11.0"
  s.source       = { :http => "https://dev-ctlzip-s3.s3.eu-west-1.amazonaws.com/Phingers/2.0.0/phingers.framework.zip" }

  s.vendored_frameworks = '*.framework'
  s.preserve_paths = 'OnyxCamera.framework', 'onyx-core.framework'
  s.requires_arc            = true
  s.xcconfig                = { 'FRAMEWORK_SEARCH_PATHS' => '$(inherited)', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64 armv7' }
  s.pod_target_xcconfig     = { 'ENABLE_BITCODE' => 'NO', 'OTHER_LDFLAGS' => '-lObjC', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64 armv7' }
  
  s.source_files = 'OnyxCamera.framework/Versions/A/Headers/**/*.h', 'OnyxCore.framework/Versions/A/Headers/**/*.h'
  #s.pod_target_xcconfig     = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64 armv7' }
s.user_target_xcconfig = { 'ENABLE_BITCODE' => 'NO', 'LD_RUNPATH_SEARCH_PATHS' => '/usr/lib/swift $(inherited)', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64 armv7' }

  s.resource_bundles = {
    'Resources' => ['OnyxCamera.framework/Resources/*.tflite', 'onyx-core.framework/Resources/Assets.car']
  }

  s.frameworks              = 'UIKit', 'CoreText', 'CoreMedia', 'AVFoundation', 'AssetsLibrary'
  s.dependency                'TensorFlowLiteObjC'
#  s.user_target_xcconfig = {  'ENABLE_BITCODE' => 'NO', 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64 armv7' }                             

end
