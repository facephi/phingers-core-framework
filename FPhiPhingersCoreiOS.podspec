#
#  Be sure to run `pod spec lint FPhiSelphIDWidgetiOSLight.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see https://guides.cocoapods.org/syntax/podspec.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|
  s.name         = "FPhiPhingersCoreiOS"
  s.version      = "8.0.11"
  s.summary      = "Phingers widget for Fingerprint detection and recognition"
  s.description  = <<-DESC
                  Phingers widget for Fingerprint detection and recognition.
                  DESC
  s.homepage     = "http://www.facephi.com"
  s.license      = {
                    :type => "Commercial", 
                    :text => <<-LICENSE
                    © Facephi 2021. All rights reserved.
                    LICENSE
                  }
  s.authors      = { "FacePhi" => "support@facephi.com" }
  
  s.platform     = :ios, "11.0"
  s.source       = { :git => "https://gitlab.com/telosid/plugins/specs.git" }

  s.dependency 'OnyxCamera', '8.0.11'

end
